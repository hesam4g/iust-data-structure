#include "LList.h"


LinkedList::LinkedList()
{
	char s[1] = {'\0'};
	head = Node::makeNewNode(s,0,0);
	tail = head;
	current = head;
	size = 0;
}

void LinkedList::insert(char* s)
{
	if (current == tail)
	{
		Node* temp = Node::makeNewNode(s,0,Node::getSizeOfString(s));
		current->next = temp;
		tail = temp;
		size++;
		return;
	}
	Node* temp = Node::makeNewNode(s,current->next,Node::getSizeOfString(s));
	current->next = temp;
	size++;
	return;
}

void LinkedList::append(char* s)
{
	Node* temp = Node::makeNewNode(s,0,Node::getSizeOfString(s));
	tail->next = temp;
	tail = temp;
	size++;
	return;
}

void LinkedList::remove()
{
	if (current == tail)
	{
		cout<<"Remove failed because there is no available item to remove!"<<endl;
		return;
	}

	if (current->next == tail)
	{
		tail = current;
		delete current->next;
		current->next = tail->next = 0;
		size--;
		return;
	}

	Node* temp = current->next;
	current->next = temp->next;
	delete temp;
	size--;
	return;
}

void LinkedList::moveToStart()
{
	current = head;
	return;
}

void LinkedList::moveToEnd()
{
	current = head;
	while (current->next != tail)
		current = current->next;
	return;
}

void LinkedList::moveToPos(int p)
{
	if (p > size)
	{
		cout<<"index is out of range!"<<endl;
		return;
	}

	current = head;
	for (int i=0 ; i<p ; i++)
		current = current->next;
	return;
}

void LinkedList::prev()
{
	if (current = head)
	{
		cout<<"Out of range!"<<endl;
		return;
	}
	Node* temp = current;
	current = head;
	while (current->next != temp)
		current = current->next;
	return;
}

void LinkedList::next()
{
	if (current == tail)
	{
		cout<<"Out of range!"<<endl;
		return;
	}
	current = current->next;
	return;
}

int LinkedList::length()
{
	return size;
}

int LinkedList::currentPos()
{
	Node* temp = head;
	int counter = 0;
	while (temp != current)
	{
		temp = temp->next;
		counter++;
	}
	return counter;
}

char* LinkedList::getValue()
{
	if (current == tail)
	{
		cout<<"No available item to return!"<<endl;
		return 0;
	}
	return current->next->string;
}

bool LinkedList::isEmpty()
{
	return !(size);
}

ostream& operator<<(ostream& output , LinkedList& l)
{
	int temp = l.currentPos();
	l.moveToStart();
	for (int i=0 ; i<l.length() ; i++)
	{
		output<<l.getValue()<<" ";
		l.next();
	}
	output<<'\n';
	l.moveToPos(temp);
	return output;
}