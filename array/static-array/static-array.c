#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 10

bool validate_index_insert(int, int);
bool validate_index_delete(int, int);
void insert(int *, int, int, int *);
void insert_at_start(int *, int, int *);
void insert_at_end(int *, int, int *);
void delete(int *, int, int *);
void delete_from_start(int *, int *);
void delete_from_end(int *, int *);
void print(int *, int);
int access_element(int *, int, int *);

int main() {

  int arr[MAX_SIZE] = {0};

  int count = 0;

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
  insert_at_end(arr, 4, &count);
  insert_at_end(arr, 5, &count);
  print(arr, count);
  delete(arr, 4, &count);
  print(arr, count);
}

bool validate_index_insert(int i, int count) {
  /*
   * Validating the index i
   * 0 <= i <= count return true
   */
  if (i >= 0 && i <= count) {
    return true;
  }
  printf("Cant't Insert. Invalid values for i, either i is less than "
         "array length or "
         "greater than the defined size \n");
  return false;
}

void insert(int *arr, int n, int i, int *count) {

  if (!validate_index_insert(i, *count)) {
    return;
  }

  if ((*count) < MAX_SIZE) {
    // If the list is not full
    int index;
    for (index = (*count); index > i; index--) {
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

bool validate_index_delete(int i, int count) {
  /*
   * Validating the index i
   * 0 <= i < count return true
   */
  if (i >= 0 && i < count) {
    return true;
  }
  printf("Cant't Remove. Invalid values for i, either i is less than "
         "array length or "
         "greater than the defined size \n");
  return false;
}

void delete(int *arr, int i, int *count) {

  if (!validate_index_delete(i, *count)) {
    return;
  }

  // If count is greater than or equal to zero there is element in list
  if (*count > 0) {
    // Till count-1 as we dont want garbage there after 1 element is removed
    // Now list is count - 1 length
    for (; i < *count - 1; i++) {
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

int access_element(int *arr, int i, int *count) {
  if (validate_index_delete(i, *count))
    return arr[i];
}
