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
    struct Node* prev;
    int data;
    struct Node* next;
}*first = NULL;


void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;
    
    for(i=1; i<n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

int Length(struct Node* p)
{
    int len=0;
    while(p!=NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}


void Display(struct Node* p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}



void insert(struct Node* p, int value, int index)
{
    struct Node* q;
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = value;
    if(index < 0 || index > Length(p)+1) return;
    // insertion at the end
    if(index == Length(p)+1)
    {
       while(p->next!=NULL)  p=p->next;
       t->next = NULL;
       t->prev = p;
       p->next = t;
    }
    else if(index == 0)
    {
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        int i;
        for(i=0; i<index-1; i++)
        {
            q = p;
            p = p->next;
        }
        t->prev = q;
        q->next = t;
        t->next = p;
        p->prev = t;
    }
}

void Delete(struct Node* p, int index)
{
    int sizeList = Length(p);
    if(index < 0 || index >= sizeList) return;
    else if(index==0)
    {
        p->next->prev = NULL;
        free(p);
        first = p->next;
    }
    else
    {
        int i;
        for(i=0; i<index; i++)  p=p->next;
        if(index == sizeList-1)
        {
            p->prev->next = NULL;
            free(p);
        }
        else
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
        }
    }
}

void reverse(struct Node* p)
{
    struct Node* temp;
    while(p!=NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p!=NULL && p->next == NULL) first = p;
    }
}

int main()
{
    int A[] = {1,2,3,4,5};
    create(A, 5);
    
    reverse(first);
    Display(first);
}

