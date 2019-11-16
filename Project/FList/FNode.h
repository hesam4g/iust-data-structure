#include <iostream>
using std::cout;


class Node
{

	friend class LinkedList;

private:
	static Node* freeLists[20];
	char* string;
	Node* next;
	int sizeOfString;

public:
	Node(char* , Node*);
	static int getSizeOfString(char*);
	static Node* makeNewNode(char* , Node* , int);
	void operator delete(void*);
	static void showFreeListsStatus();
	
};