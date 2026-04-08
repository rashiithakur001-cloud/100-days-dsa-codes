/* You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
Return the minimum number of cameras needed to monitor all nodes of the tree.
Example 1:
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2   */
#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int cameras = 0;

// DFS function
int dfs(struct TreeNode* root) {
    if (root == NULL)
        return 2; // NULL nodes are covered

    int left = dfs(root->left);
    int right = dfs(root->right);

    // If any child needs camera
    if (left == 0 || right == 0) {
        cameras++;
        return 1; // place camera here
    }

    // If any child has camera
    if (left == 1 || right == 1) {
        return 2; // covered
    }

    // Else, needs camera
    return 0;
}

int minCameraCover(struct TreeNode* root) {
    if (dfs(root) == 0)
        cameras++;
    return cameras;
}
 