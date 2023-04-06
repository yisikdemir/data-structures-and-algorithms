// ------------------------------------------------------------------------------
//
// Author: Yunus Emre Işıkdemir
// 
// Create Date: 06/02/2021
// 
// ------------------------------------------------------------------------------

#include <stdio.h>

#include <stdlib.h>

#define MIN_INT - 32768;

struct Node {
  int data;
  struct Node * next;
}* first = NULL, * second = NULL, * third = NULL;

void Display(struct Node * p) {
  while (p != NULL) {
    printf("%d ", p -> data);
    p = p -> next;
  }
  printf("\n");
}

void create(int A[], int n) {
  int i;
  struct Node * t;
  struct Node * last;
  first = (struct Node * ) malloc(sizeof(struct Node));
  first -> data = A[0];
  first -> next = NULL;
  last = first;

  for (i = 1; i < n; i++) {
    t = (struct Node * ) malloc(sizeof(struct Node));
    t -> data = A[i];
    t -> next = NULL;
    last -> next = t;
    last = t;
  }
}

void create2(int A[], int n) {
  int i;
  struct Node * t;
  struct Node * last;
  second = (struct Node * ) malloc(sizeof(struct Node));
  second -> data = A[0];
  second -> next = NULL;
  last = second;

  for (i = 1; i < n; i++) {
    t = (struct Node * ) malloc(sizeof(struct Node));
    t -> data = A[i];
    t -> next = NULL;
    last -> next = t;
    last = t;
  }
}

void Merge(struct Node * p, struct Node * q) {
  struct Node * last;
  if (p -> data < q -> data) {
    third = last = p;
    p = p -> next;
    third -> next = NULL;
  } else {
    third = last = q;
    q = q -> next;
    third -> next = NULL;
  }
  while (p != NULL && q != NULL) {
    if (p -> data < q -> data) {
      last -> next = p;
      last = p;
      p = p -> next;
      last -> next = NULL;
    } else {
      last -> next = q;
      last = q;
      q = q -> next;
      last -> next = NULL;
    }
  }
  if (p) last -> next = p;
  if (q) last -> next = q;
}

int main() {
  int A[] = {
    10,
    20,
    40,
    50,
    60
  };
  int B[] = {
    15,
    28,
    25,
    30,
    55
  };
  create(A, 5);
  create2(B, 5);

  Merge(first, second);

  Display(third);
}