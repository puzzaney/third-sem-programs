#include <stdio.h>
#include <stdlib.h>

struct Node {
  int info;
  struct Node *prev;
  struct Node *next;
};

typedef struct Node NodeType;

NodeType *head = NULL, *tail = NULL, *temp, *nNode;

void insert(int item) {
  nNode = (NodeType *)malloc(sizeof(NodeType));
  nNode->info = item;

  printf("%d inserted\n", item);
  if (head == NULL) {
    nNode->next = NULL;
    nNode->prev = NULL;
    head = nNode;
    tail = nNode;
    return;
  }
  tail->next = nNode;
  nNode->prev = tail;
  nNode->next = NULL;
  tail = nNode;
}

void delete() {
  if (head == NULL) {
    printf("No items to delete\n");
    return;
  }
  temp = tail;
  tail = temp->prev;
  printf("%d deleted\n", temp->info);
  free(temp);
  if (tail == NULL) {
    head = NULL;
    return;
  }
}

void display() {
  if (head == NULL) {
    printf("No items in the list\n");
    return;
  }
  temp = head;
  while (temp->next != NULL) {
    printf("%d\t", temp->info);
    temp = temp->next;
  }
}

int main() {
  insert(10);
  insert(20);
  insert(30);
  delete ();
  display();
}
