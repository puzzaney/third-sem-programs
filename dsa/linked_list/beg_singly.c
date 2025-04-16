#include <stdio.h>
#include <stdlib.h>

struct Node {
  int info;
  struct Node *next;
};

typedef struct Node NodeType;

NodeType *head = NULL, *nNode, *temp;

void insert(int item) {
  nNode = (NodeType *)malloc(sizeof(NodeType));
  nNode->info = item;
  nNode->next = head;
  head = nNode;
  printf("%d is inserted to the linked list\n", item);
}

void delete() {
  if (head == NULL)
    printf("Linked List is empty\n");
  else {
    temp = head;
    printf("%d is deleted from Linked List\n", temp->info);
    head = temp->next;
    free(temp);
  }
}

void display() {
  printf("Displaying content of list: \n");
  temp = head;
  while (temp != NULL) {
    printf("%d\n", temp->info);
    temp = temp->next;
  }
}

int main() {
  insert(10);
  insert(20);
  insert(30);
  display();
  delete ();
  display();
}
