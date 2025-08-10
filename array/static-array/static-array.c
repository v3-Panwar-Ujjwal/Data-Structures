#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 10

bool validate_index(int, int);
void insert(int *, int, int, int *);
void insert_at_start(int *, int, int *);
void insert_at_end(int *, int, int *);
void delete(int *, int, int *);
void delete_from_start(int *, int *);
void delete_from_end(int *, int *);
void print(int *, int);
void access_element(int *, int);

int main() {

  int arr[MAX_SIZE];

  int count = -1;

  /*
   * Array menu for now.
  printf("=========== Array interface ============\n");
  printf("1. Insert an element at start of the array\n");
  printf("2. Insert an element at the end of the array\n");
  printf("3. Insert an element at index i in the array\n");
  printf("4. Delete an element from the end of the array\n");
  printf("5. Delete an element from the start of the array\n");
  printf("6. Delete an elemenent at index i in the array\n");
  printf("7. Return the count of the elements in the array\n");
  printf("8. Print the current array\n");
  printf("9. Access the element at index i\n");
   */
  insert_at_end(arr, 1, &count);
  insert_at_end(arr, 2, &count);
  insert_at_end(arr, 3, &count);
  insert(arr, 4, 2, &count);
  insert(arr, 5, 3, &count);
  insert(arr, 6, 5, &count);
  print(arr, count);
  delete(arr, 3, &count);
  print(arr, count);
  delete(arr, 3, &count);
  print(arr, count);
  delete_from_end(arr, &count);
  delete(arr, 2, &count);
  print(arr, count);
}

bool validate_index(int i, int count) {
  /*
   * Validating the index i
   * If index is greater than or equal to count or greater than MAX_SIZE or less
   * than 0 Return with an error
   */
  if (i > count || i > MAX_SIZE || i < 0) {
    printf("Cant't Insert/Remove. Invalid values for i, either i is less than "
           "array "
           "length or "
           "greater than the defined size \n");
    return false;
  }
  return true;
}

void insert(int *arr, int n, int i, int *count) {

  if (!validate_index(i, *count)) {
    return;
  }

  if ((*count) < MAX_SIZE) {
    // If the list is not full
    int index;
    for (index = (*count) + 1; index > i; index--) {
      // Copy element of current index to index + 1;
      arr[index] = arr[index - 1];
    }
    arr[i] = n;
    // Increase count after inserting the element
    (*count)++;
  } else {
    printf("List is full, can't insert any more elements\n");
    return;
  }
};

void insert_at_start(int *arr, int n, int *count) { insert(arr, n, 0, count); }

void insert_at_end(int *arr, int n, int *count) {
  insert(arr, n, *count, count);
}

void delete(int *arr, int i, int *count) {

  if (!validate_index(i, *count)) {
    return;
  }

  // If count is greater than or equal to zero there is element in list
  if (*count >= 0) {
    for (; i < *count; i++) {
      // Copy element at i+1 index to current index
      arr[i] = arr[i + 1];
    }
    // Reduce count after removal of the element
    (*count)--;
  } else {
    printf("List is empty, Can't remove any elements");
    return;
  }
};

void delete_from_start(int *arr, int *count) { delete(arr, 0, count); };

void delete_from_end(int *arr, int *count) { delete(arr, *count, count); };

void print(int *arr, int count) {
  int i;
  for (i = 0; i < count; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n");
};
