/* Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:
Input: root = [1]
Output: [[1]]
Example 3:
input: root = []
Output: []  */
#include <stdio.h>
#include <stdlib.h>

// Definition for binary tree
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

// Create queue
struct Queue* createQueue(int cap) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = cap;
    q->front = q->size = 0;
    q->rear = cap - 1;
    q->data = (struct TreeNode**)malloc(cap * sizeof(struct TreeNode*));
    return q;
}

int isEmpty(struct Queue* q) {
    return (q->size == 0);
}

void enqueue(struct Queue* q, struct TreeNode* item) {
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = item;
    q->size++;
}
struct TreeNode* dequeue(struct Queue* q) {
    struct TreeNode* item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}
// Level Order Traversal
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
     *returnSize = 0;
      return NULL;
    }
    int** result = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
struct Queue* q = createQueue(1000);
    enqueue(q, root);
int level = 0;
while (!isEmpty(q)) {
    int size = q->size;
result[level] = (int*)malloc(size * sizeof(int));
(*returnColumnSizes)[level] = size;
for (int i = 0; i < size; i++) {
    struct TreeNode* curr = dequeue(q);
    result[level][i] = curr->val;
if (curr->left)
     enqueue(q, curr->left);
    if (curr->right)
     enqueue(q, curr->right);
 }
   level++;
    }
 *returnSize = level;
    return result;
}