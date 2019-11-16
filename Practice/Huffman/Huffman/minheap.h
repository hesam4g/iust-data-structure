#ifndef MINHEAP_H
#define MINHEAP_H
#include "Node.h"

class MinHeap{
public:
    MinHeap(int);
    int current;
    void insert(Node*);
    Node* remove();
    void show();

private:
    Node** heapList;
    int maxSize;
    int leftChild(int);
    int rightChild(int);
    int parent(int);
    void bubbleUp(int);
    void bubbleDown(int);
    void swap(int,int);

};

#endif
