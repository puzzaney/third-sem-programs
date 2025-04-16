#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *prev;
  int info;
  struct Node *next;
};

typedef struct Node NodeType;

NodeType *head = NULL, *nNode, *temp;

void insert(int item) {
  nNode = (NodeType *)malloc(sizeof(NodeType));
  nNode->info = item;
  nNode->prev = NULL;
  nNode->next = head;
  if (head != NULL)
    head->prev = nNode;
  head = nNode;

  printf("%d inserted!\n", item);
}

void delete() {
  if (head == NULL) {
    printf("No items in the list \n");
    return;
  }

  temp = head;
  head = temp->next;
  if (head != NULL)
    head->prev = NULL;
  printf("Deleted %d\n", temp->info);
  free(temp);
}

void display() {
  if (head == NULL) {
    printf("No items in the list\n");
    return;
  }
  printf("Displaying Item in the list: \n");
  temp = head;
  while (temp != NULL) {
    printf("%d\t", temp->info);
    temp = temp->next;
  }
}

int main() {
  delete ();
  insert(10);
  delete ();
  display();
  insert(20);
  insert(30);
  insert(40);
  delete ();
  display();
}
