#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
private:
    vector<int> heap;
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int leftChild(int i)
    {
        return 2 * i + 1;
    }
    int rightChild(int i)
    {
        return 2 * i + 2;
    }

public:
    void insert(int v)
    {
        heap.push_back(v);
        // 需要调整堆中顺序以满足最小堆性质，向上调整，依次比较父节点即可
        int i = heap.size() - 1;
        while (i && heap[parent(i)] > v)
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    // 移除根元素
    void removeRoot()
    {
        /**
         * 移除根元素之后需要向下调整
         * 直接删除之后变成两个堆，不易处理
         * 常用做法：
         * 将根节点与末尾节点互换位置，然后向下调整，选择子节点中较小的互换，直至移动到末尾。
         */
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        int i = 0;
        while (leftChild(i) < heap.size() - 1 && rightChild(i) < heap.size() - 1)
        {
            if (heap[leftChild(i)] < heap[rightChild(i)])
            {
                swap(heap[i], heap[leftChild(i)]);
                i = leftChild(i);
            }
            else
            {
                swap(heap[i], heap[rightChild(i)]);
                i = rightChild(i);
            }
        }
        if (leftChild(i) < heap.size() - 1)
        {
            swap(heap[i], heap[leftChild(i)]);
            i = leftChild(i);
        }
        else if (rightChild(i) < heap.size() - 1)
        {
            swap(heap[i], heap[rightChild(i)]);
            i = rightChild(i);
        }
    }
    int getMin()
    {
        return heap[0];
    }
    void print()
    {
        for (int i = 0; i < heap.size(); i++)
        {
            cout << heap[i] << endl;
        }
    }
};