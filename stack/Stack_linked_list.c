// ------------------------------------------------------------------------------
//
// Author: Yunus Emre Işıkdemir
// 
// Create Date: 08/02/2021
// 
// ------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void display()
{
    struct Node* p;
    p=top;
    while(p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("\n");
}

void push(int value)
{
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = value;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node* t = top;
    int x = -1;
    if(top == NULL)
        printf("Stack is Empty\n");
    else
    {
        x = t->data;
        top = top->next;
        free(t);    
    }
    return x;
}

void deallocateHeap()
{
    struct Node* p = top;
    struct Node* temp;
    while(p!=NULL)
    {
        temp = p;
        p=p->next;
        free(temp);
    }
}

int stackSize(struct Node* p)
{
    int len=0;
    while(p!=NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

int peek(int pos)
{
    struct Node* p = top;
    if(pos<0 || pos>=stackSize(p)) return -1;
    int i;
    for(i=0; i<pos; i++)  p = p->next;
    return p->data;
}


int Peek(int pos)
{
    int x=-1;
    struct Node* p = top;
    if(pos<0) return -1;
    int i;
    for(i=0; i<pos && p!=NULL; i++)  p = p->next;
    
    if(p!=NULL)
        return p->data;
    return x;
}

int stackTop()
{
    if(top) 
        return top->data;
    return -1;
}

int isEmpty()
{
    return top ? 0 : 1;
}

int isFull()
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    int r = t ? 0 : 1;
    free(t);
    return r;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    
    display();
    
    printf("\%d", isFull());
    
    deallocateHeap();
}







