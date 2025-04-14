#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float evaluate(char *prefix) {
  int len = strlen(prefix);
  float stack[100];
  int top = -1;

  // Start from right to left for prefix
  for (int i = len - 1; i >= 0; i--) {
    // If operand, push to stack
    if (isdigit(prefix[i])) {
      stack[++top] = prefix[i] - '0';
    }
    // If operator, pop two elements and apply the operator
    else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' ||
             prefix[i] == '/' || prefix[i] == '$' || prefix[i] == '^') {
      float operand1 = stack[top--];
      float operand2 = stack[top--];

      switch (prefix[i]) {
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
      case '$':
      case '^':
        stack[++top] = pow(operand1, operand2);
        break;
      }
    }
  }

  return stack[top];
}

int main() {
  char prefix[100];
  printf("Enter prefix expression (operators and single-digit operands): ");
  scanf("%s", prefix);

  float result = evaluate(prefix);
  printf("Result: %.2f\n", result);

  return 0;
}
