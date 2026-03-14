                                                                                                                                                           /*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50
Output:
10 20 30 40 50
Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
int n;
scanf("%d", &n);
if (n <= 0) return 0;
struct Node *head = NULL, *temp = NULL, *newNode = NULL;
for (int i = 0; i < n; i++) {
    int value;
scanf("%d", &value);
    newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
   if (head == NULL) {
    head = newNode;
 head->next = head;
     temp = head;
} else {
    newNode->next = head;
    temp->next = newNode;
    temp = newNode;
}
    }
temp = head;
  if (head != NULL) {
    do {
 printf("%d ", temp->data);
    temp = temp->next;
} while (temp != head);
    }
return 0;
}