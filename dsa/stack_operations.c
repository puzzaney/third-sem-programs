#include <stdio.h>
#include <stdlib.h>

int n = 5;
int stack[5];
int top = -1;

// defining ADT of stack
void push(int item);
void pop();
void display();

void push(int item) {
  if (top == n - 1) {
    printf("Stack Full\n");
  }
  top++;
  stack[top] = item;
  printf("%d pushed into stack\n", item);
  display();
}

void pop() {
  if (top == -1) {
    printf("Stack Underflow!\n");
  }
  int item = stack[top];
  printf("%d poped out of stack\n", stack[top]);
  top--;
  display();
}

void display() {
  printf("Items in Stack\n");
  for (int i = top; i >= 0; i--) {
    printf("%d\t", stack[i]);
  }
  printf("\n");
}
void main() {
  pop();
  push(5);
  push(6);
  pop();
  push(3);
  display();
}
