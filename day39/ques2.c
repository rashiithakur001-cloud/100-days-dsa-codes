/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:
Input: nums = [1], k = 1
Output: [1]
Example 3:
Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]*/

#include <stdlib.h>
typedef struct Node {
    int key;
    int freq;
    struct Node* next;
} Node;
#define HASH_SIZE 10007
Node* table[HASH_SIZE];
int hash(int key) {
    if (key < 0) key = -key;
    return key % HASH_SIZE;
}
void insert(int key) {
    int h = hash(key);
    Node* curr = table[h];
    while (curr) {
        if (curr->key == key) {
            curr->freq++;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->freq = 1;
    newNode->next = table[h];
    table[h] = newNode;
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    for (int i = 0; i < HASH_SIZE; i++)
        table[i] = NULL;
    for (int i = 0; i < numsSize; i++)
        insert(nums[i]);
    Node** buckets = (Node**)calloc(numsSize + 1, sizeof(Node*));
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = table[i];
        while (curr) {
            Node* next = curr->next;
            curr->next = buckets[curr->freq];
            buckets[curr->freq] = curr;
            curr = next;
        }
    }
    int* result = (int*)malloc(sizeof(int) * k);
    int count = 0;
    for (int i = numsSize; i >= 0 && count < k; i--) {
        Node* curr = buckets[i];
        while (curr && count < k) {
            result[count++] = curr->key;
            curr = curr->next;
        }
    }
    *returnSize = k;
    return result;
}