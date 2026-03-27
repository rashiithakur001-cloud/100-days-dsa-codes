/* Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6    */
#include <stdio.h>
#include <stdlib.h>
// Tree node structure
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
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
// Find node
struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return findNode(root->left, val);
    else
        return findNode(root->right, val);
}
// LCA in BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;
    }
    return NULL;
}
int main() {
    int N;
    scanf("%d", &N);
    struct TreeNode* root = NULL;
// Input BST values
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    int p_val, q_val;
    scanf("%d %d", &p_val, &q_val);
    struct TreeNode* p = findNode(root, p_val);
    struct TreeNode* q = findNode(root, q_val);
    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL)
        printf("%d\n", lca->val);
    return 0;
}