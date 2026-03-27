/* Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2   */
#include <stdio.h>
#include <stdlib.h>
// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}
// Find a node by value
struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;
    if (val < root->val)
        return findNode(root->left, val);
    else
        return findNode(root->right, val);
}
// LCA function (BST)
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}
int main() {
    struct TreeNode* root = NULL;
// Build BST: [6,2,8,0,4,7,9,null,null,3,5]
    int values[] = {6, 2, 8, 0, 4, 7, 9, 3, 5};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }
    // Example 1: p = 2, q = 8
    struct TreeNode* p = findNode(root, 2);
    struct TreeNode* q = findNode(root, 8);

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL)
        printf("LCA of %d and %d is: %d\n", p->val, q->val, lca->val);
    else
        printf("LCA not found\n");
    // Example 2: p = 2, q = 4
    p = findNode(root, 2);
    q = findNode(root, 4);
    lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL)
        printf("LCA of %d and %d is: %d\n", p->val, q->val, lca->val);
    return 0;
}