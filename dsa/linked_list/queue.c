#include <stdio.h>
#include <stdlib.h>

struct Node {
  int info;
  struct Node *next;
  struct Node *prev;
};

typedef struct Node NodeType;

NodeType *head = NULL, *tail = NULL, *nNode, *temp;

void enqueue(int item) {
  nNode = (NodeType *)malloc(sizeof(NodeType));
  nNode->info = item;
  if (head == NULL) {
    head = nNode;
    tail = nNode;
  } else {
    nNode->next = head;
    nNode->prev = NULL;
    head->prev = nNode;
    head = nNode;
  }
  printf("%d inserted\n", item);
}

void dequeue() {
  if (head == NULL) {
    printf("Queue Empty\n");
    return;
  } else if (head == tail) {
    printf("%d dequeued\n", head->info);
    free(head);
    head = NULL;
    tail = NULL;
    return;
  }
  temp = tail;
  tail = temp->prev;
  tail->next = NULL;
  printf("%d dequeued\n", temp->info);
  free(temp);
}

void display() {
  if (head == NULL) {
    printf("Queue Empty\n");
    return;
  }
  temp = head;
  printf("Displaying Items: \n");
  while (temp != NULL) {
    printf("%d\n", temp->info);
    temp = temp->next;
  }
}

int main() {
  dequeue();
  display();
  enqueue(1);
  display();
  dequeue();
  enqueue(2);
  enqueue(3);
  enqueue(4);
  dequeue();
  display();

  return 0;
}
