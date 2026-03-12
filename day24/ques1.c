/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node *link;
};
struct node* add(struct node *start, int num) {
    struct node *newnode, *ptr;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = num;
    newnode->link = NULL;
    if (start == NULL)
        return newnode;
    ptr = start;
    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = newnode;
    return start;
}
struct node* delete(struct node *start, int key) {
    struct node *ptr = start, *pre = NULL;
    if (start == NULL)
        return start;
    if (ptr->info == key) {
        start = ptr->link;
        free(ptr);
        return start;
    }
    while (ptr != NULL && ptr->info != key) {
        pre = ptr;
        ptr = ptr->link;
    }
    if (ptr == NULL)
        return start;
    pre->link = ptr->link;
    free(ptr);
    return start;
}
void show(struct node *start) {
    while (start != NULL) {
        printf("%d ", start->info);
        start = start->link;
    }
}
int main() {
    int n, i, value, key;
    struct node *start = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        start = add(start, value);
    }
    scanf("%d", &key);
    start = delete(start, key);
    show(start);
    return 0;
}