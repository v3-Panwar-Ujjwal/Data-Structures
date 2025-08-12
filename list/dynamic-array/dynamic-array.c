#include <stdio.h>
#include <stdlib.h>

/*
 * Create a list of integers size n
 */
void create_list(int **arr, int n) {
  *arr = (int *)malloc(n * sizeof(int));
  if (*arr == NULL)
    printf("Memory allocation failed\n");
}

/*
 * Insert an integer in the list at ith position.
 */
void insert(int **, int i);

/*
 * Remove an element from ith position from the list
 */
void delete(int **);

int count();

int main() {
  int *arr;
  int n = 10;
  create_list(&arr, n);
  int i = 0;
  printf("Enter the numbers\n");
  for (i = 0; i < 10; i++) {
    printf("Enter at %d:", i);
    scanf("%d", arr + i);
  }

  for (i = 0; i < 10; i++)
    printf("%d", *(arr + i));

  free(arr);
  arr = NULL;
  return 0;
}
