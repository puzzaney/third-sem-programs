#include <stdio.h>
#include <stdlib.h>

struct Node {
  int info;
  struct Node *next;
};

typedef struct Node NodeType;

NodeType *head = NULL, *tail = NULL, *nNode, *temp;

void insert(int item) {
  nNode = (NodeType *)malloc(sizeof(NodeType));
  nNode->info = item;
  if (head == NULL) {
    head = nNode;
    tail = nNode;
  } else {
    nNode->next = head;
    head = nNode;
  }
  tail->next = head;
  printf("%d inserted\n", item);
}

void delete() {
  if (head == NULL) {
    printf("Empty list\n");
    return;
  }
  temp = head;
  if (head == tail) {
    head = NULL;
    tail = NULL;
  } else {
    head = temp->next;
    tail->next = head;
  }
  printf("%d deleted\n", temp->info);
  free(temp);
}

void display() {
  if (head == NULL) {
    printf("No items to display\n");
    return;
  }
  temp = head;
  do {
    printf("%d\t", temp->info);
    temp = temp->next;
  } while (temp != head);
}

int main() {
  display();
  delete ();
  insert(5);
  display();
  delete ();
  display();
  insert(10);
  delete ();
  insert(10);
  insert(20);
  insert(30);
  display();
  return 0;
}
