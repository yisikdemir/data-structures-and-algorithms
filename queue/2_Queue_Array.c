// ------------------------------------------------------------------------------
//
// Author: Yunus Emre Işıkdemir
// 
// Create Date: 13/02/2021
//
// ------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

struct Queue {
  int * A;
  int size;
  int front;
  int rear;
};

void create(struct Queue * q, int size) {
  q -> size = size;
  q -> front = q -> rear = -1;
  q -> A = (int * ) calloc(q -> size, sizeof(int));
}

void enqueue(struct Queue * q, int x) {
  if (q -> rear == q -> size - 1)
    printf("Queue is full!");
  else
    q -> A[++q -> rear] = x;
}

int dequeue(struct Queue * q) {
  int x = -1;
  if (q -> front == q -> rear)
    printf("Queue is Empty");
  else
    x = q -> A[++q -> front];
  return x;
}

void display(const struct Queue * q) {
  int i;
  for (i = q -> front + 1; i <= q -> rear; i++)
    printf("%d ", q -> A[i]);
  printf("\n");
}

void deallocateHeap(struct Queue * q) {
  free(q -> A);
}

int main() {
  struct Queue q;
  create( & q, 5);
  enqueue( & q, 1);
  enqueue( & q, 2);
  enqueue( & q, 3);
  display( & q);
}