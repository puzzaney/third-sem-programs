#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int precedence(char ch) {
  switch (ch) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  }
  return -1;
}

void reverse(char *str) {
  int len = strlen(str);
  for (int i = 0, j = len - 1; i < j; i++, j--) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

void infix_to_prefix(char *infix, char *prefix) {
  char stack[100];
  int top = -1;
  int i, j = 0;
  char temp[100];
  int len = strlen(infix);

  // Step 1: Reverse the infix expression
  strcpy(temp, infix);
  reverse(temp);

  // Step 2: Replace ( with ) and vice versa
  for (i = 0; i < len; i++) {
    if (temp[i] == '(')
      temp[i] = ')';
    else if (temp[i] == ')')
      temp[i] = '(';
  }

  // Step 3: Convert to postfix
  for (i = 0; i < len; i++) {
    if (isalnum(temp[i])) {
      prefix[j++] = temp[i];
    } else if (temp[i] == '(') {
      stack[++top] = temp[i];
    } else if (temp[i] == ')') {
      while (top != -1 && stack[top] != '(') {
        prefix[j++] = stack[top--];
      }
      if (top != -1)
        top--; // Pop '('
    } else {
      while (top != -1 && precedence(stack[top]) > precedence(temp[i])) {
        prefix[j++] = stack[top--];
      }
      stack[++top] = temp[i];
    }
  }

  while (top != -1) {
    prefix[j++] = stack[top--];
  }
  prefix[j] = '\0';

  // Step 4: Reverse the resultant expression
  reverse(prefix);
}

int main() {
  char infix[100], prefix[100];
  printf("Enter infix expression: ");
  scanf("%s", infix);
  infix_to_prefix(infix, prefix);
  printf("Prefix expression: %s\n", prefix);
  return 0;
}
