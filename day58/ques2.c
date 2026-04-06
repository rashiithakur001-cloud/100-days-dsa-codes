/* Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]   */
#include <stdio.h>
#include <stdlib.h>

// Tree node structure
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

// Build tree helper
struct TreeNode* build(int preorder[], int inorder[], int inStart, int inEnd,
                       int* preIndex, int* inorderMap, int offset) {
    
    if (inStart > inEnd)
        return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = createNode(rootVal);

    int inIndex = inorderMap[rootVal - offset];

    root->left = build(preorder, inorder, inStart, inIndex - 1,
                       preIndex, inorderMap, offset);

    root->right = build(preorder, inorder, inIndex + 1, inEnd,
                        preIndex, inorderMap, offset);

    return root;
}

// Function to build tree
struct TreeNode* buildTree(int preorder[], int preorderSize,
                           int inorder[], int inorderSize) {
    
    int min = inorder[0], max = inorder[0];

    // Find range for mapping
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] < min) min = inorder[i];
        if (inorder[i] > max) max = inorder[i];
    }

    int size = max - min + 1;

    int* inorderMap = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < inorderSize; i++) {
        inorderMap[inorder[i] - min] = i;
    }

    int preIndex = 0;

    return build(preorder, inorder, 0, inorderSize - 1,
                 &preIndex, inorderMap, min);
}

// (Optional) Print tree in level order for verification
void printPreorder(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

// Driver code
int main() {
    int preorder[] = {3,9,20,15,7};
    int inorder[] = {9,3,15,20,7};

    int n = 5;

    struct TreeNode* root = buildTree(preorder, n, inorder, n);

    // Print preorder of constructed tree (for checking)
    printPreorder(root);

    return 0;
}