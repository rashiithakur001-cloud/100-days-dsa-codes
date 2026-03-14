/*Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Example 1:
Input: head = [1,2,2,1]
Output: true
Example 2:
Input: head = [1,2]
Output: false
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *next = NULL;
while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
 return prev;
}
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;
    struct ListNode *slow = head, *fast = head;
// Find middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
// Reverse second half
    struct ListNode* secondHalf = reverse(slow);
    struct ListNode* firstHalf = head;
// Compare both halves
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val)
            return false;
firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
return true;
}