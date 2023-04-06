// ------------------------------------------------------------------------------
//
// Author: Yunus Emre Işıkdemir
// 
// Create Date: 08/02/2021
// 
// ------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *A;
    int Top;
    int size;
};

void create(struct Stack* s)
{
    printf("Enter the size of stack: ");
    scanf("%d", &s->size);
    s->A = (int*)calloc(s->size, sizeof(int));
    s->Top=-1;
}

void display(const struct Stack* s)
{
    int i;
    for(i=s->Top; i >= 0; i--)
        printf("%d\n", s->A[i]);
    printf("\n");
}

void push(struct Stack* s, int value)
{
    if(s->Top != s->size-1)
    {
        s->Top++;
        s->A[s->Top] = value;
    }
    else
    {
        printf("Stack overflow\n");
    }
}

int pop(struct Stack* s)
{
    int x = -1;
    if(s->Top == -1)
        printf("Stack Underflow\n");
    else
        x = s->A[s->Top--];
    return x;
}

int isEmpty(const struct Stack* s)
{
    return s->Top == -1;
}

int isFull(const struct Stack* s)
{
    return s->Top == s->size-1;
}

int stackTop(const struct Stack* s)
{
    if(!isEmpty(s))
        return s->A[s->Top];
    return -1;
}

int Peek(const struct Stack* s, int index)
{
    int x = -1;
    // En �ste 1 dersek, bottom n. index olacak
    if(s->Top-index+1 < 0  || index<0)
        printf("\nInvalid Index \n");
    x = s->A[s->Top-index+1];    
    return x;
}

void deallocateHeap(struct Stack* s)
{
    free(s->A);
}

int main()
{
    struct Stack s;
    create(&s);
    
    push(&s, 3);
    push(&s, 2);
    push(&s, 7);
    
    display(&s);
    
    printf("\n%d", stackTop(&s));
    
    deallocateHeap(&s);
}

