/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:
Input: root = [1]
Output: [[1]]
Example 3:
Input: root = []
Output: []
*/
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
if (root == NULL) {
  *returnSize = 0;
  return NULL;
    }
int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int level = 0;
while (front < rear) {
    int size = rear - front;
    result[level] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[level] = size;
for (int i = 0; i < size; i++) {
    struct TreeNode* node = queue[front++];
     result[level][i] = node->val;
    if (node->left != NULL)
    queue[rear++] = node->left;
 if (node->right != NULL)
    queue[rear++] = node->right;
        }
 level++;
    }
*returnSize = level;
    return result;
}