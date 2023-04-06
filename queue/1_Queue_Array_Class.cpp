// ------------------------------------------------------------------------------
//
// Author: Yunus Emre Işıkdemir
// 
// Create Date: 13/02/2021
//
// ------------------------------------------------------------------------------

#include <iostream>

using namespace std;

class Queue
{
private:
    int* A;
    int size;
    int front;
    int rear;

public:
    Queue(int size);
    ~Queue();
    void enqueue(int x);
    int dequeue();
    void display() const;
};


Queue::Queue(int size)
{
    this->size = size;
    front = rear = -1;
    A = new int[this->size];
}


Queue::~Queue()
{
    delete[] A;
}

void Queue::enqueue(int x)
{
    if (rear == size - 1)
        cout << "Queue is full!" << endl;
    else
        A[++rear] = x;
}

int Queue::dequeue()
{
    int x = -1;
    if (front == rear)
        cout << "Queue is Empty" << endl;
    else
        x = A[++front];
    return x;
}

void Queue::display() const
{
    for (int i = front + 1; i <= rear; i++)
        cout << A[i] << " ";
    cout << endl;
}


int main()
{
    int A[] = { 1,2,3,4,5 };
    int size = sizeof(A) / sizeof(A[0]);
    Queue q(size);

    for (int i = 0; i < size; i++)
        q.enqueue(A[i]);

    q.display();
        
}







