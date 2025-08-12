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
void print(const int *, int);
void access_element(int *, int, int *);

int main() {

  int arr[MAX_SIZE] = {0};

  int count = 0;

  insert_at_end(arr, 1, &count);
  insert_at_end(arr, 2, &count);
  insert_at_end(arr, 3, &count);
  insert_at_end(arr, 4, &count);
  insert_at_end(arr, 5, &count);
  // 1 2 3 4 5
  print(arr, count);
  delete_from_end(arr, &count);
  // 1 2 3 4
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

  return false;
}

void insert(int *arr, int n, int i, int *count) {

  if (!validate_index_insert(i, *count)) {
    printf("Cant't Insert. Invalid values for i, either i is less than "
           "array length or "
           "greater than the defined size \n");
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
}

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
  return false;
}

void delete(int *arr, int i, int *count) {
  if (!validate_index_delete(i, *count)) {
    printf("Can't Remove. Invalid values for i, either i is less than "
           "array length or "
           "greater than the defined size \n");
    return;
  }
  // If count is greater than or equal to zero there is element in list
  if (*count > 0) {
    // Till count-1 as we dont want garbage there after 1 element is removed
    // Now list is count - 1 length
    for (; i < *count - 1; i++) {
      arr[i] = arr[i + 1];
    }
    (*count)--;
  } else {
    printf("List is empty, Can't remove any elements");
    return;
  }
}

void delete_from_start(int *arr, int *count) { delete(arr, 0, count); }

void delete_from_end(int *arr, int *count) { delete(arr, *count - 1, count); }

void print(const int *arr, int count) {
  int i;
  for (i = 0; i < count; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void access_element(int *arr, int i, int *count) {
  if (validate_index_delete(i, *count))
    printf("%d", arr[i]);
  else
    printf("Can't access element. Invalid values for i, either i is less than "
           "array length or "
           "greater than the defined size \n");
}
