#include <stdio.h>
#include <stdlib.h>

int size = 5;
int q[5];

int front = -1;
int rear = -1;
void enqueue(int item) {
  if (rear >= size - 1) {
    printf("Queue Overflow\n");
  } else {
    if (front == -1) {
      front = rear = 0;
    } else {
      rear++;
    }
    q[rear] = item;
    printf("%d enqueued\n", item);
  }
}

void dequeue() {
  if (front == -1) {
    printf("Queue underflow\n");
  } else {
    int item = q[front++];
    printf("%d dequeued\n", item);
  }
}

void display() {
  for (int i = front; i <= rear; i++) {
    printf("%d\t", q[i]);
  }
  printf("\n");
}

int main() {
  dequeue();
  enqueue(1);
  dequeue();
  enqueue(5);
  enqueue(6);
  enqueue(7);
  display();
}
