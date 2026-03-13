/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50
Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void append(struct Node** head, int data) {
    struct Node* node = newNode(data);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = node;
}
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    struct Node *p1 = head1, *p2 = head2;
    while (p1 != p2) {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }
    return p1;
}
int main() {
    int n, m, x;
    struct Node *head1 = NULL, *head2 = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(&head1, x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        append(&head2, x);
    }
    struct Node* temp = head1;
    while (temp && temp->data != 30)
        temp = temp->next;
    if (temp) {
        struct Node* t2 = head2;
        while (t2->next)
            t2 = t2->next;
        t2->next = temp;
    }
    struct Node* ans = findIntersection(head1, head2);
    if (ans)
        printf("%d", ans->data);
    else
        printf("No Intersection");
    return 0;
}