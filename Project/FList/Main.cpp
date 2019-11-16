#include "LList.h"
#include <iostream>

using namespace std;

int main()
{
	LinkedList A;
	A.insert("Amin");
	A.append("Fallahi");
	cout<<A;
	A.moveToEnd();
	A.next();
	A.insert("1234");
	cout<<A;
	Node::showFreeListsStatus();
	A.moveToEnd();
	A.remove();
	cout<<A;
	Node::showFreeListsStatus();
	A.append("amin");
	cout<<A;
	Node::showFreeListsStatus();
	return 0;
}