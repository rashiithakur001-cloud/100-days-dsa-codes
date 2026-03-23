/*Problem Statement:
Find the height (maximum depth) of a given binary tree.
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
Output Format:
- Print the height of the tree
Example:
Input:
7
1 2 3 4 5 -1 -1
Output:
3
*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    if (data == -1)
        return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int height(struct Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;
    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(arr[i]);
    }
    int j = 1;
    for (int i = 0; i < n && j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n)
                nodes[i]->left = nodes[j++];
            if (j < n)
                nodes[i]->right = nodes[j++];
        }
    }
    return nodes[0];
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    int h = height(root);
    printf("%d\n", h);
    return 0;
}