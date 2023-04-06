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
}* head = NULL, * last = NULL;

void create(int A[], int n) {
  int i;
  struct Node * t, * last;
  head = (struct Node * ) malloc(sizeof(struct Node));

  head -> data = A[0];
  head -> next = NULL;

  last = head;

  for (i = 1; i < n; i++) {
    t = (struct Node * ) malloc(sizeof(struct Node));
    t -> data = A[i];
    t -> next = NULL;

    last -> next = t;

    last = t;
  }
}

void display(struct Node * p) {
  while (p != NULL) {
    printf("%d ", p -> data);
    p = p -> next;
  }
}

void Rdisplay(struct Node * p) {
  if (p != NULL) {
    printf("%d ", p -> data);
    Rdisplay(p -> next);
  }
}

void freeList(struct Node * p) {
  struct Node * tmp;

  while (p != NULL) {
    tmp = p;
    p = p -> next;
    free(tmp);
  }
}

int countNodes(struct Node * p) {
  int count = 0;
  while (p != NULL) {
    count++;
    p = p -> next;
  }
  return count;
}

int countNodesRecursive(struct Node * p) {
  if (p != NULL)
    return countNodesRecursive(p -> next) + 1;
  return 0;
}

int sumAll(struct Node * p) {
  int sum = 0;
  while (p != NULL) {
    sum += p -> data;
    p = p -> next;
  }
  return sum;
}

int sumAllRecursion(struct Node * p) {
  if (p != NULL)
    return sumAllRecursion(p -> next) + p -> data;
  return 0;
}

int findMax(struct Node * p) {
  int maximum = p -> data;
  while (p != NULL) {
    if (p -> data > maximum) maximum = p -> data;
    p = p -> next;
  }
  return maximum;
}

int RfindMax(struct Node * p) {
  int x;
  if (p != NULL) {
    x = RfindMax(p -> next);
    return (x > p -> data) ? x : p -> data;
  }
  return MIN_INT;
}

struct Node * linearSearch(struct Node * p, int key) {
  while (p != NULL) {
    if (key == p -> data) return p;
    p = p -> next;
  }
  return NULL;
}

struct Node * RlinearSearch(struct Node * p, int key) {
  if (p != NULL) {
    if (key == p -> data) return p;
    return linearSearch(p -> next, key);
  }
  return NULL;
}

struct Node * MoveToHeadLSearch(struct Node * p, int key) {
  struct Node * q = NULL;
  while (p != NULL) {
    if (key == p -> data) {
      q -> next = p -> next;
      p -> next = head;
      head = p;
      return p;
    }
    q = p;
    p = p -> next;
  }
  return NULL;
}

void Insert(struct Node * p, int value, int position) {
  if (position < 0 || position > countNodes(p)) return;

  int i;
  struct Node * t = (struct Node * ) malloc(sizeof(struct Node));
  t -> data = value;

  if (position == 0) {
    t -> next = head;
    head = t;
  } else {
    p = head;
    for (i = 0; i < position - 1; i++)
      p = p -> next;
    t -> next = p -> next;
    p -> next = t;
  }
}

void InsertLast(struct Node * p, int value) {
  struct Node * t = (struct Node * ) malloc(sizeof(struct Node));
  t -> data = value;
  t -> next = NULL;

  if (head == NULL)
    head = last = t;
  else {
    last -> next = t;
    last = t;
  }
}

void InsertSorted(struct Node * p, int value) {
  struct Node * t = (struct Node * ) malloc(sizeof(struct Node));
  struct Node * q = NULL;
  t -> data = value;
  t -> next = NULL;

  if (head == NULL)
    head = t;
  else {
    while (p != NULL && p -> data < value) {
      q = p;
      p = p -> next;
    }

    if (p == head) {
      t -> next = head;
      head = t;
    } else {
      t -> next = q -> next;
      q -> next = t;
    }
  }
}

void Delete(struct Node * p, int position) {
  if (position == 0) {
    head = p -> next;
    free(p);
  } else {
    struct Node * q = NULL;
    while (p != NULL) {
      if (!position) {
        q -> next = p -> next;
        free(p);
      }
      q = p;
      p = p -> next;
      position--;
    }
  }
}

void efficientDelete(struct Node * p, int position) {
  if (position < 0) return;
  else if (position == 0) {
    head = p -> next;
    free(p);
  } else {
    struct Node * q = NULL;
    int i;
    for (i = 0; i < position && p != NULL; i++) {
      q = p;
      p = p -> next;
    }
    if (p != NULL) {
      q -> next = p -> next;
      free(p);
    }
  }
}

int isSorted(struct Node * p) {
  struct Node * q = p;
  while (p != NULL) {
    if (q -> data > p -> data)
      return 0;
    q = p;
    p = p -> next;
  }
  return 1;
}

int alternativeIsSorted(struct Node * p) {
  int x = MIN_INT;
  while (p != NULL) {
    if (p -> data < x)
      return 0;
    x = p -> data;
    p = p -> next;
  }
  return 1;
}

void removeDuplicate(struct Node * p) {
  struct Node * q;
  while (p != NULL) {
    q = p;
    p = p -> next;
    if (p != NULL && q -> data == p -> data) {
      q -> next = p -> next;
      free(p);
      p = q;
    }
  }
}

void reverse(struct Node * p) {
  int SIZE = countNodes(p);
  int * arr = (int * ) calloc(SIZE, sizeof(int));
  int i = SIZE - 1;
  while (p != NULL) {
    arr[i--] = p -> data;
    p = p -> next;
  }
  i = 0;
  p = head;
  while (p != NULL) {
    p -> data = arr[i++];
    p = p -> next;
  }
  free(arr);
}

void reverseLinks(struct Node * p) {
  struct Node * q;
  struct Node * t;
  q = p;
  p = p -> next;
  t = p -> next;
  q -> next = NULL;
  while (t != NULL) {
    p -> next = q;
    q = p;
    p = t;
    t = t -> next;
  }
  p -> next = q;
  head = p;
}

void recursionReverse(struct Node * p, struct Node * q) {
  if (p != NULL) {
    recursionReverse(p -> next, p);
    p -> next = q;
  } else
    head = q;
}

void isLoop(struct Node * p) {
  struct Node * q = NULL;
  while (p != NULL && q != NULL) {
    p = p -> next;
    q = q -> next -> next;
    if (q == p) {
      printf("There is a Loop");
      break;
    }
  }
  printf("Linear Linked List");
}

int main() {

  InsertSorted(head, 3);
  InsertSorted(head, 4);
  InsertSorted(head, 5);
  InsertSorted(head, 6);
  InsertSorted(head, 7);
  InsertSorted(head, 8);
  InsertSorted(head, 9);

  display(head);

  printf("\n");
  recursionReverse(head, NULL);
  display(head);
}