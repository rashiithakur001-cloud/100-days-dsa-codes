/* Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7   */
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Create new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
 struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
 struct Node* root = newNode(arr[0]);
    queue[rear++] = root;
int i = 1;
while (front < rear && i < n) {
struct Node* curr = queue[front++];
 if (arr[i] != -1) {
    curr->left = newNode(arr[i]);
    queue[rear++] = curr->left;
}
  i++;
    if (i < n && arr[i] != -1) {
    curr->right = newNode(arr[i]);
    queue[rear++] = curr->right;
}
    i++;
    }
 free(queue);
    return root;
}
// Zigzag Traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;
struct Node** queue = (struct Node**)malloc(1000 * sizeof(struct Node*));
    int front = 0, rear = 0;
queue[rear++] = root;
int leftToRight = 1;
while (front < rear) {
 int size = rear - front;
 int* level = (int*)malloc(size * sizeof(int));
for (int i = 0; i < size; i++) {
    struct Node* curr = queue[front++];
int index = leftToRight ? i : (size - 1 - i);
    level[index] = curr->data;
if (curr->left)
    queue[rear++] = curr->left;
 if (curr->right)
    queue[rear++] = curr->right;
        }
// Print level
 for (int i = 0; i < size; i++) {
     printf("%d ", level[i]);
        }
free(level);
    leftToRight = !leftToRight; // toggle direction
    }

    free(queue);
}
int main() {
    int n;
    scanf("%d", &n);
int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
struct Node* root = buildTree(arr, n);
    zigzagTraversal(root);
free(arr);
    return 0;
}
