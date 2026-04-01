/* Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:
Input: root = [1,2,3,4,null,null,null,5]
Output: [1,3,4,5]
Example 3:
Input: root = [1,null,3]
Output: [1,3]
Example 4:
Input: root = []
Output: []  */
#include <stdio.h>
#include <stdlib.h>

// Definition for binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Queue structure
struct Queue {
    struct TreeNode** data;
    int front, rear, size, capacity;
};
struct Queue* createQueue(int cap) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = cap;
    q->front = q->size = 0;
    q->rear = cap - 1;
    q->data = (struct TreeNode**)malloc(cap * sizeof(struct TreeNode*));
    return q;
}
int isEmpty(struct Queue* q) {
    return q->size == 0;
}
void enqueue(struct Queue* q, struct TreeNode* node) {
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = node;
    q->size++;
}
struct TreeNode* dequeue(struct Queue* q) {
    struct TreeNode* node = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}
// Right Side View
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
int* result = (int*)malloc(2000 * sizeof(int));
    struct Queue* q = createQueue(2000);
    enqueue(q, root);
int level = 0;
while (!isEmpty(q)) {
        int size = q->size;
for (int i = 0; i < size; i++) {
    struct TreeNode* curr = dequeue(q);
// Last node of level → right view
 if (i == size - 1) {
    result[level++] = curr->val;
}
if (curr->left)
    enqueue(q, curr->left);
if (curr->right)
 enqueue(q, curr->right);
        }
    }
*returnSize = level;
    return result;
}

 