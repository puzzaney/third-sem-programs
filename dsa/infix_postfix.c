#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int precedence(char operator) {
  switch (operator) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
  case '$':
    return 3;
  default:
    return -1;
  }
}

void infix_to_postfix(char *infix, char *postfix) {
  int i, j = 0;
  int len = strlen(infix);
  char stack[100];
  int top = -1;

  for (i = 0; i < len; i++) {
    // If character is operand
    if (isalnum(infix[i])) {
      postfix[j++] = infix[i];
    }
    // If character is '('
    else if (infix[i] == '(') {
      stack[++top] = infix[i];
    }
    // If character is ')'
    else if (infix[i] == ')') {
      while (top > -1 && stack[top] != '(') {
        postfix[j++] = stack[top--];
      }
      if (top > -1 && stack[top] == '(') {
        top--; // Remove '('
      }
    }
    // If character is operator
    else {
      while (top > -1 && stack[top] != '(' &&
             precedence(infix[i]) <= precedence(stack[top])) {
        postfix[j++] = stack[top--];
      }
      stack[++top] = infix[i];
    }
  }

  // Pop remaining operators
  while (top > -1) {
    postfix[j++] = stack[top--];
  }

  postfix[j] = '\0';
}

int main() {
  char infix[100], postfix[100];
  printf("Enter infix expression: ");
  scanf("%s", infix);

  infix_to_postfix(infix, postfix);
  printf("Postfix expression: %s\n", postfix);

  return 0;
}
