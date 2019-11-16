#ifndef NODE_H
#define NODE_H

class Node{
    friend class MinHeap;
    friend class Hoffman;
public:
    Node(int,char,Node*,Node*);
private:
    int data;
    char key;
    Node* left;
    Node* right;
};


#endif // NODE_H
