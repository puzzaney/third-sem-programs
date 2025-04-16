#include <stdio.h>
#include <stdlib.h>

struct Node {
  int info;
  struct Node *next;
  struct Node *prev;
};

typedef struct Node NodeType;

NodeType *head, *tail, *temp, *nNode;

void insert(int item) {
  nNode = (NodeType *)malloc(sizeof(NodeType));
  nNode->info = item;
  if (head == NULL) {
    tail = nNode;
    head = nNode;
    tail->next = head;
    head->prev = tail;
  } else {
    head->prev = nNode;
    tail->next = nNode;
    nNode->next = head;
    nNode->prev = tail;
    head = nNode;
  }
  printf("%d inserted\n", item);
}

void delete() {
  if (head == NULL) {
    printf("No items to delete\n");
    return;
  }
  if (head == tail) {
    printf("%d deleted\n", head->info);
    free(head);
    head = NULL;
    tail = NULL;
    return;
  } else {
    temp = head;
    head = temp->next;
    tail->next = head;
    head->prev = tail;
    printf("%d deleted\n", temp->info);
    free(temp);
  }
}

void display() {
  if (head == NULL) {
    printf("No items to display\n");
    return;
  }
  temp = head;
  do {
    printf("%d\n", temp->info);
    temp = temp->next;
  } while (temp != head);
}

int main() {
  delete ();
  display();
  insert(5);
  insert(6);
  insert(7);
  delete ();
  delete ();
  display();
  insert(8);
  display();
}
