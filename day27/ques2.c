/*Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.
Examples:
Input: head = 1 -> 3 -> 4, pos = 2
Output: true
Explanation: The linked list looks like
A loop is present in the list, and it is removed.
Input: head = 1 -> 8 -> 3 -> 4, pos = 0
Output: true
Explanation: 
The Linked list does not contains any loop. 
Input: head = 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: The linked list looks like 
A loop is present in the list, and it is removed.*/

#include<stdio.h>
struct Node {
    int data;
    struct Node* next;
};
void removeLoop(struct Node* head) {
    if (!head || !head->next) return;
struct Node *slow = head, *fast = head;
    int loopExists = 0;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
if (slow == fast) {
 loopExists = 1;
 break;
 }
    }
if (loopExists) {
     slow = head;
if (slow == fast) {
  while (fast->next != slow)
    fast = fast->next;
} 
 else {
 while (slow->next != fast->next) {
   slow = slow->next;
    fast = fast->next;
 }
    }
 fast->next =NULL;
    }
}