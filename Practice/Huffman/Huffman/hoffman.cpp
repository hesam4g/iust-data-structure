#include "hoffman.h"
#include <iostream>

using namespace std;

Hoffman::Hoffman(){
    MinHeap heap(50);
    char sign;
    int freq;
    cout<<"Please enter your desired charecter and its frequency respectively: ";
    cin>>sign>>freq;
    while(sign != '&'){
        Node* temp = new Node(freq,sign,0,0);
        heap.insert(temp);
        cout<<"Again please enter your desired charecter and its frequency respectively\n(To stop entering data enter '&' sign): ";
        cin>>sign>>freq;
    }

    Node* temp1;
    Node* temp2;
    Node* temp3;
    while(heap.current > 2){
        temp1 = heap.remove();
        temp2 = heap.remove();
        temp3 = new Node(temp1->data + temp2->data ,'&',temp1,temp2);
        heap.insert(temp3);
    }
    temp1 = heap.remove();
    temp2 = heap.remove();
    temp3 = new Node(temp1->data + temp2->data ,'&',temp1,temp2);
    root = temp3;

}

void Hoffman::decode(char* bins){
    Node* temp = root;
    while(bins[0] != '\0'){
        if(bins[0] == '1'){
            temp = temp->right;
            bins++;
        }
        else{
            temp = temp->left;
            bins++;
        }
    }
    cout<<temp->key<<endl;
}
