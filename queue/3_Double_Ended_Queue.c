// ------------------------------------------------------------------------------
//
// Author: Yunus Emre Işıkdemir
// 
// Create Date: 13/02/2021
//
// ------------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>

struct Node {

  int front;
  int rear;
  int size;
  int * Q;

};

void create(struct Node * st, int n) {

  st -> size = n;
  st -> front = -1;
  st -> rear = -1;
  st -> Q = (int * ) malloc(st -> size * sizeof(int));

}

void insert_from_front(struct Node * st, int x) {

  if (st -> front == -1 && st -> rear == -1) {
    st -> front = 0;
    st -> rear = 0;
    st -> Q[st -> rear] = x;
    st -> rear = st -> rear + 1;
  } else if (st -> rear == st -> size) {
    printf("Queue is full:\n");
  } else {
    st -> Q[st -> rear] = x;
    st -> rear = st -> rear + 1;
  }

}

void del_from_back(struct Node * st) {

  if (st -> front == -1 && st -> rear == -1) {
    printf("It is empty:");
  } else {
    if (st -> rear < st -> front) {
      printf("It is empty:");
      st -> front = -1;
      st -> rear = -1;
    } else {
      printf("%d is deleted element\n", st -> Q[st -> rear - 1]);
      st -> rear = st -> rear - 1;
      st -> size = st -> size - 1;
    }
  }
}

void del_from_front(struct Node * st) {

  if (st -> rear == -1 && st -> front == -1) {
    printf("Queue is empty:\n");
    st -> front = -1;
    st -> rear = -1;
  } else if (st -> front == st -> rear) {
    printf("Queue is empty:\n");
    st -> front = -1;
    st -> rear = -1;
  } else {
    printf("%d is deleted element:\n", st -> Q[st -> front]);
    st -> front = st -> front + 1;
  }

}

void insert_from_back(struct Node * st, int x) {
  if (st -> front == -1 && st -> rear == -1) {
    st -> front = 0;
    st -> rear = 0;
    st -> Q[st -> rear] = x;
    st -> rear = st -> rear + 1;
  } else if (st -> rear == st -> size) {
    printf("Queue is full:");
  } else {
    st -> Q[st -> rear] = x;
    st -> rear = st -> rear + 1;
  }
}

void display(struct Node st) {
  int i = st.front;
  for (; i != st.rear; i++) {
    printf("%d\t", st.Q[i]);
  }
  printf("\n");
}

int main()
{
    struct Node queue;
    create(&queue, 5);
    insert_from_front(&queue, 2);
    insert_from_front(&queue, 3);
    insert_from_front(&queue, 4);
    insert_from_back(&queue, 1);
    del_from_front(&queue);
    del_from_back(&queue);
    display(queue);

    return 0;
}
