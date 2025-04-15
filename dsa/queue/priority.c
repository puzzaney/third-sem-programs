// creation of process
#include <stdio.h>
int pqueue[10], n = 5;
int front = -1, rear = -1;

void check_priority(int);

void enqueue(int item) {
  if (rear == n - 1) {
    printf("Unable to insert!\n");
    return;
  }
  if (rear == -1) {
    front = rear = 0;
    pqueue[rear] = item;
  } else {
    check_priority(item);
    rear++;
  }
  printf("%d Inserted!\n", item);
}
void check_priority(int item) {
  int i, j;
  for (i = 0; i <= rear; i++) {
    if (item >= pqueue[i]) {
      for (j = rear + 1; j > i; j--) {
        pqueue[j] = pqueue[j - 1];
      }
      pqueue[i] = item;
      return;
    }
  }
  pqueue[i] = item;
}
void dequeue() {
  if (front == -1) {
    printf("Unable to delete\n");
    return;
  }
  int item = pqueue[front];
  if (front == rear)
    front = rear = -1;
  else
    front++;
  printf("%d Deleted\n", item);
}

void display() {
  printf("Elements are:\n");
  for (int i = front; i <= rear; i++)
    printf("%d\t", pqueue[i]);
}

int main() {
  enqueue(10);
  enqueue(20);
  enqueue(5);
  enqueue(40);
  enqueue(25);
  dequeue();
  display();
  return 0;
}
