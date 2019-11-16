#include "minheap.h"
#include <iostream>

using namespace std;

Node::Node(int d,char c,Node* l,Node* r){
    data = d;
    key = c;
    left = l;
    right = r;
}

MinHeap::MinHeap(int size){
    maxSize = size;
    heapList = new Node*[maxSize];
    current = 0;
}

int MinHeap::parent(int i){
    if(i>=current || i<0){
        cout<<"Index out of range!"<<endl;
        return -1;
    }
    return (i-1)/2;
}

int MinHeap::leftChild(int i){
    if(i>=current || i<0){
        cout<<"Index out of range!"<<endl;
        return -1;
    }
    if(2*i+1<current){
        return 2*i+1;
    }
    return -1;
}

int MinHeap::rightChild(int i){
    if(i>=current || i<0){
        cout<<"Index out of range!"<<endl;
        return -1;
    }
    if(2*i+2<current){
        return 2*i+2;
    }
    return -1;
}

void MinHeap::show(){
    for(int i = 0;i<current;i++)
        cout<<heapList[i]->data<<"  ";
    cout<<endl;
}

void MinHeap::swap(int a,int b){
    Node* temp = heapList[a];
    heapList[a] = heapList[b];
    heapList[b] = temp;
}

void MinHeap::bubbleDown(int i){
    int tempLeft = leftChild(i);
    int tempRight = rightChild(i);
    if(tempLeft == -1){
        return;
    }
    if(tempRight == -1){
        if(heapList[tempLeft]->data < heapList[i]->data){
            swap(tempLeft,i);
            bubbleDown(tempLeft);
            return;
        }
    }
    else{
        int temp = tempLeft;
        if(heapList[tempLeft]->data > heapList[tempRight]->data){
            temp = tempRight;
        }
        if(heapList[i]->data > heapList[temp]->data){
            swap(temp,i);
            bubbleDown(temp);
            return;
        }
    }
}

void MinHeap::bubbleUp(int i){
    int tempParent = parent(i);
    if(tempParent == -1){
        return;
    }
    if(heapList[tempParent]->data > heapList[i]->data){
        swap(tempParent,i);
        bubbleUp(tempParent);
    }
}

void MinHeap::insert(Node* d){
    heapList[current++]=d;
    bubbleUp(current-1);
}

Node* MinHeap::remove(){
    if(current == 0){
        return 0;
    }
    swap(--current,0);
    if(current == 0){
        return heapList[current];
    }
    bubbleDown(0);
    return heapList[current];
}
