// ------------------------------------------------------------------------------
//
// Author: Yunus Emre Işıkdemir
// 
// Create Date: 08/02/2021
// 
// ------------------------------------------------------------------------------

#include<iostream>
#include<stdexcept>
#include<iomanip>
#include<math.h>
using namespace std;

class Stack
{
private:
	int* A;
	int Top;
	int size;

public:
	Stack(int size);
	void display() const;
	void push(int value);
	int pop();
	bool isEmpty() const;
	bool isFull() const;
	int stackTop() const;
	int Peek(int index) const;
	~Stack();

};


Stack::Stack(int size)
{
	this->size = size;
	Top = -1;
	A = new int[this->size];
}


void Stack::display() const
{
	for (int i = Top; i >= 0; i--)
		cout << A[i] << "\n";
	cout << "\n";
}


void Stack::push(int value)
{
	if (Top == size-1)
		cout << "Stack overflow\n";
	else
	{
		Top++;
		A[Top] = value;
	}
}


int Stack::pop()
{
	int x = -1;

	if (Top == -1)
		printf("Stack Underflow\n");
	else
	{
		x = A[Top--];
	}
	return x;
}


int Stack::Peek(int index) const
{
	int x = -1;
	if (Top - index + 1 < 0)
		cout << "Invalid Index \n";
	x = A[Top - index + 1];
	return x;
}


bool Stack::isEmpty() const
{
	return Top == -1;
}


bool Stack::isFull() const
{
	return Top == size - 1;
}


int Stack::stackTop() const
{
	if (!isEmpty())
		return A[Top];
	return -1;
}


Stack::~Stack()
{
	delete[] A;
}

int main()
{
	Stack s(7);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	s.display();
}






