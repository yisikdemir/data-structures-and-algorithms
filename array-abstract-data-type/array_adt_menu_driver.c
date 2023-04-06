// ------------------------------------------------------------------------------
//
// Author: Yunus Emre Işıkdemir
// 
// Create Date: 04/02/2021
// 
// ------------------------------------------------------------------------------

#include<stdio.h>

#include<stdlib.h>


struct Array {
  int * A;
  int size;
  int length;
};

//
void displayElements(const struct Array * arr) {
  int i;
  printf("\nElements are: ");
  for (i = 0; i < arr -> length; i++)
    printf("%d ", arr -> A[i]);
  printf("\n");
}


void append(struct Array * arr, int x) {
  
  if (arr -> length < arr -> size)
    
    arr -> A[arr -> length++] = x;
}


void insert(struct Array * arr, int index, int x) {
  
  if (index >= 0 && index <= arr -> length && arr -> length < arr -> size) {
    int i;
    for (i = arr -> length; i > index; i--)
      arr -> A[i] = arr -> A[i - 1];
    arr -> A[index] = x;
    (arr -> length) ++;
  }
}


int Delete(struct Array * arr, int index) {
  int x;
  
  if (index >= 0 && index <= arr -> size) {
    int i = 0;
    x = arr -> A[index];
    for (i = index; i < arr -> length - 1; i++)
      arr -> A[i] = arr -> A[i + 1];
    arr -> length--;
    return x;
  }
  return 0;
}


int linearSearch(const struct Array * arr, int key) {
  int i;
  for (i = 0; i < arr -> length; i++) {
    if (arr -> A[i] == key)
      return i;
  }
  return -1;
}


int binarySearch(const struct Array * arr, int key) {
  int low = 0;
  int high = arr -> length - 1;
  int middle;

  while (low <= high) {
    middle = (low + high) / 2;

    if (key == arr -> A[middle])
      return middle;

    else if (key < arr -> A[middle])
      high = middle - 1;

    else
      low = middle + 1;
  }

  return -1;
}


int binaryRecursive(const struct Array * arr, int key, int low, int high) {
  if (low <= high) {
    int middle = (low + high) / 2;
    if (key == arr -> A[middle])
      return middle;

    else if (key < arr -> A[middle])
      binaryRecursive(arr, key, low, middle - 1);

    else
      binaryRecursive(arr, key, middle + 1, high);
  } else if (low > high)
    return -1;
}


int getElement(const struct Array * arr, int index) {
  if (index < arr -> length && index >= 0)
    return arr -> A[index];
  else {
    printf("\n-Index is out of bound-");
    return -1;
  }
}


void setElement(struct Array * arr, int index, int val) {
  if (index < arr -> length && index >= 0)
    arr -> A[index] = val;
}


int getMax(const struct Array * arr) {
  int max = arr -> A[0];
  int i;
  for (i = 0; i < arr -> length; i++)
    if (arr -> A[i] > max)
      max = arr -> A[i];
  return max;
}


int getMin(const struct Array * arr) {
  int min = arr -> A[0];
  int i;
  for (i = 0; i < arr -> length; i++)
    if (arr -> A[i] < min)
      min = arr -> A[i];
  return min;
}


float getAvg(const struct Array * arr) {
  float sum = 0;
  int i;
  for (i = 0; i < arr -> length; i++)
    sum += arr -> A[i];
  return (float) sum / arr -> length;
}


int getSum(const struct Array * arr, int idx) {
  if (idx >= 0)
    return getSum(arr, idx - 1) + arr -> A[idx];
  else
    return 0;
}


void swap(int * x, int * y) {
  int temp;
  temp = * x;
  * x = * y;
  * y = temp;
}


void reverse(struct Array * arr) {
  int i, j;
  for (i = 0, j = arr -> length - 1; i < j; i++, j--)
    swap( & arr -> A[i], & arr -> A[j]);
}


void rotate(struct Array * arr) {
  int i;
  int temp = arr -> A[0];
  for (i = 0; i < arr -> length - 1; i++)
    arr -> A[i] = arr -> A[i + 1];
  arr -> A[arr -> length - 1] = temp;
}


void insertSorted(struct Array * arr, int val) {
  
  if (arr -> length == arr -> size)
    return;
  int i;
  for (i = 0; i < arr -> length; i++)
    if (arr -> A[i] > val)
      insert(arr, i, val);
  arr -> length++;
}


int isSorted(const struct Array * arr) {
  int i;
  for (i = 0; i < arr -> length - 1; i++)
    if (arr -> A[i] > arr -> A[i + 1])
      return 0;
  return 1;
}


void signSeparate(struct Array * arr) {
  int i, j;
  for (i = 0, j = arr -> length - 1; i < j;) {
    if (arr -> A[i] < 0)
      i++;
    else if (arr -> A[i] > 0) {
      swap( & arr -> A[i], & arr -> A[j]);
      j--;
    }
  }
}


struct Array * Merge(struct Array * arr1, struct Array * arr2) {
  int i, j, k;
  i = j = k = 0;
  struct Array * arr3 = (struct Array * ) malloc(sizeof(struct Array));
  arr3 -> A = (int * ) calloc(arr1 -> length + arr2 -> length, sizeof(int));

  while (i < arr1 -> length && j < arr2 -> length) {
    if (arr1 -> A[i] < arr2 -> A[j])
      arr3 -> A[k++] = arr1 -> A[i++];
    else
      arr3 -> A[k++] = arr2 -> A[j++];
  }

  for (; i < arr1 -> length; i++)
    arr3 -> A[k++] = arr1 -> A[i];

  for (; j < arr2 -> length; j++)
    arr3 -> A[k++] = arr2 -> A[j];

  arr3 -> length = k;
  arr3 -> size = arr1 -> length + arr2 -> length;
  return arr3;
}


struct Array * Union(struct Array * arr1, struct Array * arr2) {
  int i, j, k;
  i = j = k = 0;
  struct Array * arr3 = (struct Array * ) malloc(sizeof(struct Array));
  arr3 -> A = (int * ) calloc(arr1 -> length + arr2 -> length, sizeof(int));

  while (i < arr1 -> length && j < arr2 -> length) {
    if (arr1 -> A[i] < arr2 -> A[j])
      arr3 -> A[k++] = arr1 -> A[i++];
    else if (arr2 -> A[j] < arr1 -> A[i])
      arr3 -> A[k++] = arr2 -> A[j++];
    else {
      arr3 -> A[k++] = arr1 -> A[i++];
      j++;
    }
  }

  for (; i < arr1 -> length; i++)
    arr3 -> A[k++] = arr1 -> A[i];

  for (; j < arr2 -> length; j++)
    arr3 -> A[k++] = arr2 -> A[j];

  arr3 -> length = k;
  arr3 -> size = arr1 -> length + arr2 -> length;
  return arr3;
}


struct Array * Intersection(struct Array * arr1, struct Array * arr2) {
  int i, j, k;
  i = j = k = 0;
  struct Array * arr3 = (struct Array * ) malloc(sizeof(struct Array));
  arr3 -> A = (int * ) calloc(arr1 -> length + arr2 -> length, sizeof(int));

  while (i < arr1 -> length && j < arr2 -> length) {
    if (arr1 -> A[i] == arr2 -> A[j]) {
      arr3 -> A[k++] = arr1 -> A[i++];
      j++;
    } else if (arr1 -> A[i] > arr2 -> A[j])
      j++;
    else
      i++;
  }

  arr3 -> length = k;
  arr3 -> size = arr1 -> length + arr2 -> length;
  return arr3;
}


struct Array * Difference(struct Array * arr1, struct Array * arr2) {
  int i, j, k;
  i = j = k = 0;
  struct Array * arr3 = (struct Array * ) malloc(sizeof(struct Array));
  arr3 -> A = (int * ) calloc(arr1 -> length + arr2 -> length, sizeof(int));

  while (i < arr1 -> length && j < arr2 -> length) {
    if (arr1 -> A[i] == arr2 -> A[j]) {
      i++;
      j++;
    } else if (arr1 -> A[i] > arr2 -> A[j])
      j++;
    else
      arr3 -> A[k++] = arr1 -> A[i++];
  }

  for (; i < arr1 -> length; i++)
    arr3 -> A[k++] = arr1 -> A[i];

  arr3 -> length = k;
  arr3 -> size = arr1 -> length + arr2 -> length;
  return arr3;
}

int main() {
  struct Array arr1;
  int ch;
  int x, index;

  printf("Enter the size of Array: ");
  scanf("%d", & arr1.size);
  arr1.A = (int * ) calloc(arr1.size, sizeof(int));

  do {
    printf("Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    printf("enter your choice: ");
    scanf("%d", & ch);

    switch (ch) {
    case 1:
      printf("Enter an element and index: ");
      scanf("%d%d", & x, & index);
      insert( & arr1, index, x);
      break;

    case 2:
      printf("Enter the index: ");
      scanf("%d", & index);
      Delete( & arr1, index);
      printf("Deleted Element is %d\n", x);
      break;

    case 3:
      printf("Enter the element to search: ");
      scanf("%d", & x);
      index = linearSearch( & arr1, x);
      printf("Element index %d", index);
      break;

    case 4:
      printf("Sum is %d\n", getSum( & arr1, arr1.length - 1));
      break;

    case 5:
      displayElements( & arr1);
    }
  } while (ch < 6);

  free(arr1.A);
}