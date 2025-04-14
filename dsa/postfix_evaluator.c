#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float evaluate(char *postfix) {
  float stack[100];
  int top = -1;

  for (int i = 0; i < strlen(postfix); i++) {
    // If operand, push to stack
    if (isdigit(postfix[i])) {
      stack[++top] = postfix[i] - '0';
    }
    // If operator, pop two elements and apply the operator
    else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' ||
             postfix[i] == '/' || postfix[i] == '^' || postfix[i] == '$') {

      float operand2 = stack[top--];
      float operand1 = stack[top--];

      switch (postfix[i]) {
      case '+':
        stack[++top] = operand1 + operand2;
        break;
      case '-':
        stack[++top] = operand1 - operand2;
        break;
      case '*':
        stack[++top] = operand1 * operand2;
        break;
      case '/':
        stack[++top] = operand1 / operand2;
        break;
      case '^':
      case '$':
        stack[++top] = pow(operand1, operand2);
        break;
      }
    }
  }

  return stack[top];
}

int main() {
  char postfix[100];
  printf("Enter postfix expression (operators and single-digit operands): ");
  printf("\nSupported operators: +, -, *, /, ^ and $ (both for power)\n");
  scanf("%s", postfix);

  float result = evaluate(postfix);
  printf("Result: %.2f\n", result);

  return 0;
}
