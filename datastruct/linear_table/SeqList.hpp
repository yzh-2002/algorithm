#include "SeqList.h"
using namespace std;

template <class T>
SeqList<T>::SeqList(int size)
{
    // 构造函数，通过指定size定义数组长度
    if (size > 0)
    {
        maxSize = size;
        last = -1;
        data = new T[size];
        if (data == NULL)
        {
            cout << "分配内存空间失败！！" << endl;
        }
    }
}

template <class T>
SeqList<T>::SeqList(SeqList<T> &L)
{
    // 复制构造函数，用参数表中给出的已有顺序表初始化新建的顺序表
    if (L != NULL)
    {
        maxSize = L.Size();
        last = L.Length() - 1;
        data = new T[L.Size()];
        T value;
        if (data == NULL)
        {
            cout << "分配内存空间失败！！" << endl;
        }
        for (int i = 0; i < L.Size(); i++)
        {
            L.getData(i, value);
            data[i] = value;
        }
    }
}

template <class T>
void SeqList<T>::reSize(int newSize)
{
    // 私有函数：扩充顺序表的存储空间大小，新数组的元素个数为newSize
    if (newSize <= 0)
    {
        cout << "无效的数组大小" << endl;
        return;
    }
    if (newSize != maxSize)
    {
        T *newArray = new T[newSize];
        if (newArray == NULL)
        {
            cout << "分配内存空间失败！！" << endl;
            exit(1);
        }
        int n = last + 1;
        T *srcptr = data;     // 源数组首地址
        T *desptr = newArray; // 新数组首地址
        while (n--)
        {
            *desptr++ = *srcptr++;
        }
        delete[] data;
        data = newArray;
        maxSize = newSize;
    }
}

template <class T>
int SeqList<T>::Search(T &x) const
{
    for (int i = 0; i <= last; i++)
    {
        if (data[i] == x)
        {
            return i + 1;
        }
    }
}

template <class T>
int SeqList<T>::Locate(int i) const
{
    // 定位函数：函数返回第i(1 <= i <= last + 1)个表项的位置，否则函数返回0，表示定位失败。
    if (i >= 1 && i <= last + 1)
        return i;
    else
        return 0;
}

template <class T>
bool SeqList<T>::Insert(int i, T &x)
{
    // 将新元素x插入到表中第i个表项之后。函数返回插入成功的信息，若
    // 插入成功，则返回true；否则返回false。i = 0是虚拟的，实际上插入到第1个元素位置。
    if (last == maxSize - 1)
        return false; // 表满，不能插入
    if (i < 0 || i > last + 1)
        return false; // 参数i不合理，不能插入
    for (int j = last; j >= i; j--)
        data[j + 1] = data[j]; // 依次后移，空出第i号位置
    data[i] = x;               // 插入
    last++;                    // 最后位置加1
    return true;               // 插入成功
}

template <class T>
bool SeqList<T>::Remove(int i, T &x)
{
    // 从表中删除第i个表项，通过引用型参数x返回删除的元素值
    // 函数返回删除成功的信息，若删除成功则返回true，否则返回false
    if (last == -1)
        return false; // 表空，不能删除
    if (i < 1 || i > last + 1)
        return false; // 参数i不合理，不能删除
    x = data[i - 1];  // 存被删元素的值
    for (int j = i; j <= last; j++)
        data[j - 1] = data[j]; // 依次前移，填补
    last--;                    // 最后位置减1
    return true;               // 删除成功
}

template <class T>
void SeqList<T>::input()
{
    // 从标准输入(键盘)逐个数据输入，建立顺序表
    cout << "开始建立顺序表，请输入表中元素个数：";
    while (1)
    {
        cin >> last;
        if (last <= maxSize - 1)
            break;
        cout << "表元素个数输入有误，范围不能超过" << maxSize - 1 << ":";
    }
    for (int i = 0; i <= last; i++)
    {
        cin >> data[i];
        cout << i + 1 << endl;
    }
}

template <class T>
void SeqList<T>::output()
{
    // 将顺序表全部元素输出到屏幕上
    cout << "顺序表当前元素最后位置为：" << last << endl;
    for (int i = 0; i <= last; i++)
        cout << "#" << i + 1 << ":" << data[i] << endl;
}

template <class T>
SeqList<T> &SeqList<T>::operator=(SeqList<T> &L)
{
    // 重载 = 运算符，表整体赋值
    if (this == &L)
    {
        return *this;
    }
    if (this->data != NULL)
    {
        delete this->data;
    }
    maxSize = L.Size();
    last = L.Length() - 1;
    T value;
    data = new T[maxSize]; // 创建顺序表存储数组
    if (data == NULL)
    {
        cerr << "存储分配错误！" << endl;
        exit(1);
    }
    for (int i = 1; i <= last + 1; i++)
    {
        L.getData(i, value);
        data[i - 1] = value;
    }
    return *this;
}