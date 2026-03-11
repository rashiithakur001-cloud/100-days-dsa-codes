/*Given the head of a singly linked list, reverse the list, and return the reversed list.
Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []*/
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* previous = NULL;
    struct ListNode* current = head;
    struct ListNode* nextNode = NULL; // Declaring outside the loop is safer in C
while (current != NULL) {
        // 1. Save the next node
  nextNode = current->next;  
        // 2. Reverse the link
  current->next = previous;
        // 3. Move pointers one step forward
  previous = current;
  current = nextNode;
    }
   return previous;
}