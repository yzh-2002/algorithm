#include "heap.h"

int main()
{
    MinHeap heap;
    heap.insert(5);
    heap.insert(7);
    heap.insert(3);
    heap.insert(1);
    heap.insert(2);
    heap.print();
    heap.removeRoot();
    heap.print();
    return 0;
}