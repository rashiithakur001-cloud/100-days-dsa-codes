/* Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:
Input: root = [1]
Output: [[1]]
Example 3:
Input: root = []
Output: []
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100  */
#include <stdio.h>
#include <stdlib.h>

// Definition for binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Queue implementation
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
// Zigzag Level Order
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));
struct Queue* q = createQueue(2000);
    enqueue(q, root);
 int level = 0;
 int leftToRight = 1;
while (!isEmpty(q)) {
        int size = q->size;
 result[level] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[level] = size;
for (int i = 0; i < size; i++) {
    struct TreeNode* curr = dequeue(q);
 int index = leftToRight ? i : (size - 1 - i);
    result[level][index] = curr->val;
if (curr->left)
    enqueue(q, curr->left);
if (curr->right)
    enqueue(q, curr->right);
 }
 leftToRight = !leftToRight;
        level++;
    }
*returnSize = level;
    return result;
}