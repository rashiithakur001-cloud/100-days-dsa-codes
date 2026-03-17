/*Problem: Convert an infix expression to postfix notation using stack.
Input:
- Single line: infix expression (operands are single characters)
Output:
- Print the postfix expression
Example:
Input:
A+B*C
Output:
ABC*+
Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

#include <stdio.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char x) {
    stack[++top] = x;
}
char pop() {
    return stack[top--];
}
int precedence(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}
int main() {
    char infix[MAX], postfix[MAX];
    int i, k = 0;
    scanf("%s", infix);
    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop();
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    printf(postfix);
    return 0;
}