#include <stdio.h>
#include <stdlib.h>

struct Node {
  int info;
  struct Node *next;
  struct Node *prev;
};

typedef struct Node NodeType;

NodeType *head = NULL, *tail = NULL, *nNode, *temp;

void insert(int item) {
  nNode = (NodeType *)malloc(sizeof(NodeType));
  nNode->info = item;
  if (head == NULL) {
    head = nNode;
    tail = nNode;
    tail->next = head;
    head->prev = tail;
  } else {
    nNode->next = head;
    nNode->prev = tail;
    head->prev = nNode;
    tail->next = nNode;
    tail = nNode;
  }
  printf("%d inserted\n", item);
}

void delete() {
  if (head == NULL) {
    printf("No item to delete\n");
    return;
  } else if (head == tail) {
    printf("%d deleted\n", head->info);
    free(head);
    head = NULL;
    tail = NULL;
    return;
  }
  temp = tail;
  tail = temp->prev;
  tail->next = head;
  head->prev = tail;
  printf("%d deleted\n", temp->info);
  free(temp);
}

void display() {
  if (head == NULL) {
    printf("No item to display\n");
    return;
  } else if (head == tail) {
    printf("%d\n", head->info);
    free(head);
    head = NULL;
    tail = NULL;
    return;
  }
  temp = head;
  do {
    printf("%d\n", temp->info);
    temp = temp->next;
  } while (temp != head);
}

int main() {
  display();
  delete ();
  insert(5);
  insert(10);
  display();
  delete ();
  delete ();
  insert(15);
  insert(20);
  display();
  return 0;
}
