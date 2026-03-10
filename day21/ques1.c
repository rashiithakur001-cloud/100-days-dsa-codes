/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};
struct Node* newNode(int x) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->val = x;
    temp->next = NULL;
    return temp;
}
void display(struct Node* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" ");
        head = head->next;
    }
    printf("\n");
}
int main() {
    int n, x;
    scanf("%d", &n);
struct Node *head = NULL, *tail = NULL;
 for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* temp = newNode(x);
if (!head)
  head = tail = temp;
        else {
tail->next = temp;
    tail = temp;
        }
    }
display(head);
    return 0;
}