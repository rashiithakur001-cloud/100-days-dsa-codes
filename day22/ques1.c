/*Problem: Count Nodes in Linked List
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
5*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int countNodes(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}
int main() {
int n, x;
 scanf("%d", &n);
 struct Node *head = NULL, *tail = NULL;
for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    struct Node* temp = malloc(sizeof(struct Node));
temp->data = x;
temp->next = NULL;
 if (!head)
 head = tail = temp;
    else {
 tail->next = temp;
   tail = temp;
 }
    }
printf("%d\n", countNodes(head));
    return 0;
}