template <class T>
class LinearList
{
public:
    virtual int Size() const = 0;          // 求表的最大体积
    virtual int Length() const = 0;        // 求表长度
    virtual int Search(T &x) const = 0;    // 求表中搜索给定值x
    virtual int Locate(int i) const = 0;   // 求表中定位第i个元素位置
    virtual bool getData(int i, T &x) = 0; // 取第i个表项的值
    virtual bool setData(int i, T &x) = 0; // 修改第i个表项的值为x
    virtual bool Insert(int i, T &x) = 0;  // 在第i个表项后插入x
    virtual bool Remove(int i, T &x) = 0;  // 删除第i个表项，通过x返回
    virtual bool IsEmpty() = 0;            // 判表空
    virtual bool IsFull() = 0;             // 判表满
    virtual void input() = 0;              // 输入
    virtual void output() = 0;
};