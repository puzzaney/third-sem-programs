#include <stdio.h>
#include <stdlib.h>

int list[5];
int last_index = -1, n = 5;

void insert(int pos, int item) {
  // invalid cases
  if (last_index == n - 1) {
    printf("List is full!\n");
    return;
  }
  if (pos < 0 || pos > last_index + 1) {
    printf("Position is invalid!\n");
    return;
  }
  // shift one postion right
  for (int i = last_index; i >= pos; i--)
    list[i + 1] = list[i];

  list[pos] = item;
  last_index++;
  printf("\n%d is Inserted at position %d\n", item, pos);
}

void delete(int pos) {
  if (last_index == -1) {
    printf("List is empty!\n");
    return;
  }
  if (pos < 0 || pos > last_index) {
    printf("Invalid position!\n");
    return;
  }
  int item = list[pos];
  // shift left one position
  for (int i = pos; i <= last_index; i++)
    list[i] = list[i + 1];
  last_index--;
  printf("\n %d is deleted from position %d\n", item, pos);
}

void display() {
  printf("Elements are:\n");
  for (int i = 0; i <= last_index; i++)
    printf("%d\t", list[i]);
}

int main() {
  insert(0, 10);
  insert(1, 20);
  insert(1, 30);
  delete (1);
  display();
  return 0;
}
