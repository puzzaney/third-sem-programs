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
    tail->next = nNode;
    tail = nNode;
  }
  printf("%d inserted\n", item);
}

void delete() {
  if (head == NULL) {
    printf("Empty List\n");
    return;
  }
  if (head == tail) {
    printf("%d deleted\n", head->info);
    free(head);
    head = tail = NULL;
    return;
  }
  temp = head;
  while (temp->next != tail)
    temp = temp->next;
  printf("%d deleted\n", tail->info);
  free(temp->next);
  temp->next = head;
  tail = temp;
}

void display() {
  if (head == NULL) {
    printf("No items to display\n");
    return;
  }
  if (head == tail) {
    printf("%d\t", head->info);
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
  insert(6);
  insert(7);
  insert(8);
  display();
}
