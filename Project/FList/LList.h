#include "FNode.h"

using namespace std;


class LinkedList
{

private:
	Node* head;
	Node* tail;
	Node* current;
	int size;

public:
	LinkedList();
	void insert(char*);
	void append(char*);
	void remove();
	void moveToStart();
	void moveToEnd();
	void prev();
	void next();
	int length();
	int currentPos();
	void moveToPos(int);
	char* getValue();
	bool isEmpty();

	friend ostream& operator<<(ostream& , LinkedList&);

};