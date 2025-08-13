#include <stdbool.h>
#include <stdio.h>

typedef struct {
  int val;
  struct Node *next;
} Node;

Node *create_node(Node *);

int main() {
  Node *head;
  printf("Hello\n");
  return 0;
}
