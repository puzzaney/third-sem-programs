#include <stdio.h>
#include <stdlib.h>

struct Node {
  int info;
  struct Node *next;
};
typedef struct Node NodeType;
NodeType *head = NULL, *tail = NULL, *newNode, *temp;

void insert(int item) {
  newNode = (NodeType *)malloc(sizeof(NodeType));
  newNode->info = item;
  if (head == NULL) { // list empty
    newNode->next = NULL;
    head = tail = newNode;
  } else {
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
  }
  printf("%d Inserted\n", item);
}

void delete() {
  if (head == NULL)
    printf("No Elements to Delete\n");
  else if (head->next == NULL) {
    temp = head;
    head = tail = NULL;
    printf("Deleted Item is: %d\n", temp->info);
    free(temp);
  } else {
    temp = head;
    while (temp->next->next != NULL)
      temp = temp->next;
    printf("Deleted Item is: %d\n", temp->next->info);
    free(temp->next);
    temp->next = NULL;
    tail = temp;
  }
}

void display() {
  temp = head;
  while (temp != NULL) {
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
