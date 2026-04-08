/* Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1] */
 #include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
// Build tree recursively
struct TreeNode* build(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex, int map[]) {
    if (inStart > inEnd)
        return NULL;
    // Get root
    int rootVal = postorder[*postIndex];
    (*postIndex)--;
struct TreeNode* root = createNode(rootVal);
// Find root index in inorder
    int inIndex = map[rootVal + 3000];  // shift due to negative values

    // Build right subtree first
    root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex, map);
    root->left = build(inorder, postorder, inStart, inIndex - 1, postIndex, map);
 return root;
}
// Main function to call
struct TreeNode* buildTree(int inorder[], int inorderSize, int postorder[], int postorderSize) {
    int map[6001];  // values range from -3000 to 3000
// Store inorder indices
    for (int i = 0; i < inorderSize; i++) {
        map[inorder[i] + 3000] = i;
    }
 int postIndex = postorderSize - 1;
return build(inorder, postorder, 0, inorderSize - 1, &postIndex, map);
}
void preorder(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}
int main() {
    int inorder[] = {9,3,15,20,7};
    int postorder[] = {9,15,7,20,3};
  int n = 5;
struct TreeNode* root = buildTree(inorder, n, postorder, n);
    preorder(root);  
 return 0;
}

