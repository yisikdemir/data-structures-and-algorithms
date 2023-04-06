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


class LinkedList
{
private:
    Node* first;

public:
    LinkedList();
    LinkedList(int A[], int n);
    ~LinkedList();
    void Display() const;
    void Insert(int index, int x);
    int Delete(int index);
    int Length() const;
};


LinkedList::LinkedList()
    :first(NULL)
{

}


LinkedList::LinkedList(int A[], int n)
{
    Node* last;
    Node* t;
    int i = 0;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node* tmp;
    while (first != NULL)
    {
        tmp = first;
        first = first->next;
        delete tmp;
    }
}


void LinkedList::Display() const
{
    Node* p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


int LinkedList::Length() const
{
    Node* p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}


void LinkedList::Insert(int index, int x)
{
    Node* t;
    Node* p = first;
    if (index < 0 || index > Length())
        return;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}


int LinkedList::Delete(int index)
{
    Node* p;
    Node* q = NULL;
    int x = -1;

    if (index < 1 || index > Length())
        return -1;
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int A[] = { 1,2,3,4,5 };
    LinkedList l(A, 5);

    l.Insert(3, 10);
    l.Display();
}



