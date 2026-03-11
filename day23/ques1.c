/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* create(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}
void insert(struct Node** head, int value) {
    struct Node* node = create(value);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = node;
}
struct Node* merge(struct Node* a, struct Node* b) {
if (!a) return b;
if (!b) return a;
struct Node* head;
 if (a->data < b->data) {
        head = a;
        a = a->next;
    } else {
        head = b;
        b = b->next;
    }
struct Node* current = head;
    while (a && b) {
if (a->data < b->data) {
    current->next = a;
    a = a->next;
} else {
    current->next = b;
     b = b->next;
  }
     current = current->next;
}
    current->next = a ? a : b;
    return head;
}
void print(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main() {
    int n, m, x;
    struct Node *list1 = NULL, *list2 = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(&list1, x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        insert(&list2, x);
    }
    struct Node* result = merge(list1, list2);
    print(result);
    return 0;
}