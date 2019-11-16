#include "FNode.h"


Node* Node::freeLists[20] = {0,0};

Node::Node(char* s , Node* n)
{
	next = n;
	sizeOfString = getSizeOfString(s);
	string = new char[sizeOfString+1];
	for (int i=0 ; i<sizeOfString ; i++)
		string[i] = s[i];
	string[sizeOfString] = '\0';
}

int Node::getSizeOfString(char* s)
{
	int counter = 0;
	while (s[counter] != '\0')
	{
		counter++;
	}
	return counter;
}

Node* Node::makeNewNode(char* s , Node* n , int size)
{
	if (freeLists[size] == 0)
		return new Node(s,n);
	Node* temp = freeLists[size];
	freeLists[size] = freeLists[size]->next;
	temp->next = n;
	temp->sizeOfString = Node::getSizeOfString(s);
	temp->string = s;
	return ((Node*)temp);
}

void Node::operator delete(void* ptr)
{
	((Node*)ptr)->next = freeLists[((Node*)ptr)->sizeOfString];
	freeLists[((Node*)ptr)->sizeOfString] = ((Node*)ptr);
	return;
}

void Node::showFreeListsStatus()
{
	for (int c=0 ; c<20 ; c++)
	{
		cout<<"FreeList"<<c<<" :";
		Node* temp = freeLists[c];
		while (temp != 0)
		{
			cout<<temp->string<<" ";
			temp = temp->next;
		}
		cout<<"\n";
	}
}