// program to implement different operations in circular queue
#include <stdio.h>
// adt of queue
int queue[5], n = 5, front = -1, rear = -1;
void enqueue(int item);
void dequeue();
void display();

void enqueue(int item) {
  if ((front == 0 && rear == n - 1) || front == rear + 1)
    printf("\nCircuar Queue Overflow!");
  else {
    if (rear == -1)
      front = rear = 0;
    else if (rear == n - 1)
      rear = 0;
    else
      rear++;
    queue[rear] = item;
    printf("\n%d is inserted in queue", item);
  }
}

void dequeue() {
  int item;
  if (front == -1)
    printf("\nQueue Underflow.");
  else {
    item = queue[front];
    printf("\n%d is removed from queue", item);
    if (front == rear)
      front = rear = -1;
    else if (front == n - 1)
      front = 0;
    else
      front++;
  }
}

void display() {
  int i;
  printf("\nElements are:\n");
  if (rear >= front) {
    for (i = front; i <= rear; i++)
      printf("%d\t", queue[i]);
  } else {
    for (i = front; i <= n - 1; i++)
      printf("%d\t", queue[i]);

    for (i = 0; i <= rear; i++)
      printf("%d\t", queue[i]);
  }
}

int main() {
  dequeue();
  enqueue(10);
  enqueue(20);
  enqueue(30);
  dequeue();
  enqueue(40);
  enqueue(50);
  enqueue(60);
  display();
  return 0;
}
