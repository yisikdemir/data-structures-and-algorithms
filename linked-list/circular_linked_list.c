// ------------------------------------------------------------------------------
//
// Author: Yunus Emre Işıkdemir
// 
// Create Date: 06/02/2021
// 
// ------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*Head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    
    for(i=1; i<n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node* p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    }while(p != Head);
}

void RDisplay(struct Node* p)
{
    if(p->next != Head)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
    else
        printf("%d ", p->data);
}

int Length(struct Node* p)
{
    int len=0;
    do
    {
        len++;
        p = p->next;
    }while(p!=Head);
    return len;
}

void Insert(struct Node* p,int value, int index)
{
    
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = value;
    int i;
    if(index<0 || index > Length(p))
        return;
    
    if(index == 0)
    {
        
        if(Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        
        else
        {
            
            while(p->next!=Head) p=p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        for(i=0; i<index-1; i++)   p = p->next;
        t->next = p->next;
        p->next = t;
    }
}


void Delete(struct Node* p, int index)
{
    
    if(index <= 0 || index > Length(p)) return;
    
    if(index == 1)
    {
        while(p->next != Head)  p = p->next;
        
        if(Head == p)
        {
            free(p);
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else
    {
        struct Node* q;
        int i;
        for(i=0; i<index-1; i++)
        {
            q = p;
            p=p->next;
        }
        q->next = p->next;
        free(p);
    }
}

int main()
{
    int A[] = {8,3,9,6,2};
    create(A, 5);
    
    Delete(Head, 15);
    
    Display(Head);
}

