#ifndef HOFFMAN_H
#define HOFFMAN_H
#include "Node.h"
#include "minheap.h"
#include <iostream>

using namespace std;

class Hoffman{

private:
    Node* root;
    //MinHeap heap;

public:
    Hoffman();
    void decode(char*);

};

#endif // HOFFMAN_H
