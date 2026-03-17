/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
Input:
- Postfix expression with operands and operators
Output:
- Print the integer result
Example:
Input:
2 3 1 * + 9 -
Output:
-4
Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node* next;
};
struct Node* top = NULL;
void push(int value) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = value;
  newNode->next = top;
 top = newNode;
}
int pop() {
   if (top == NULL) {
    printf("Stack Underflow\n");
    exit(1);
 }
    int value = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return value;
}
int main() {
    char exp[100];
    int i = 0;
    fgets(exp, sizeof(exp), stdin);
while (exp[i] != '\0') {
if (exp[i] == ' ' || exp[i] == '\n') {
    i++;
 continue;
}
if (exp[i] >= '0' && exp[i] <= '9') {
    push(exp[i] - '0');
}
else {
    int b = pop();
    int a = pop();
    int result;
switch (exp[i]) {
 case '+': result = a + b; break;
 case '-': result = a - b; break;
 case '*': result = a * b; break;
 case '/': result = a / b; break;
 default:
printf("Invalid operator\n");
    return 1;
}
    push(result);
}
    i++;
}
    printf("%d\n", pop());
    return 0;
}