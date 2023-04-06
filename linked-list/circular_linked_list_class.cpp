// ------------------------------------------------------------------------------
//
// Author: Yunus Emre Işıkdemir
// 
// Create Date: 06/02/2021
// 
// ------------------------------------------------------------------------------

#include<iostream>
#include<stdexcept>
#include<iomanip>
#include<math.h>
#define MIN_INT -32768;

using namespace std;

struct Node
{
	int data;
	Node* next;
};


class CircularLinkedList
{
private:
	Node* head;
public:
	CircularLinkedList(int A[], int n);
	void Display() const;
	void recursiveDisplay(Node* p) const;
	Node* getHead() const;
	~CircularLinkedList();
};


CircularLinkedList::CircularLinkedList(int* A, int n)
{
	Node* t;
	Node* tail;

	head = new Node;
	head->data = A[0];
	head->next = head;
	tail = head;

	for (int i = 0; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = tail->next;
		tail->next = t;
		tail = t;
	}
}


void CircularLinkedList::Display() const
{
	Node* p = head;
	do
	{
		cout << p->data << " -> " << flush;
		p = p->next;
	} while (p != head);
	cout << endl;
}


void CircularLinkedList::recursiveDisplay(Node* p) const
{
	if (p->next != head)
	{
		cout << p->data << " -> " << flush;
		recursiveDisplay(p->next);
	}
	else
		cout << p->data << " -> " << flush;
}


CircularLinkedList::~CircularLinkedList()
{
	Node* p = head;
	while (p->next != head)  p = p->next;
	while (p != head)
	{
		p->next = head->next;
		delete head;
		head = p->next;
	}
	if (p == head)
	{
		delete head;
		head = nullptr;
	}
}


Node* CircularLinkedList::getHead() const
{
	return head;
}

int main()
{
	int A[] = { 1, 3, 5, 7, 9 };
	CircularLinkedList cl(A, sizeof(A) / sizeof(A[0]));

	cl.Display();

	Node* h = cl.getHead();
	cl.recursiveDisplay(h);
}



