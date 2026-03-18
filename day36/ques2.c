/*Design your implementation of the circular double-ended queue (deque).
Implement the MyCircularDeque class:
MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
Example 1:
Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]
Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
*/
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int *a, f, r, sz, k;
} MyCircularDeque;
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* q = malloc(sizeof(MyCircularDeque));
    q->a = malloc(sizeof(int) * k);
    q->f = 0; q->r = -1; q->sz = 0; q->k = k;
    return q;
}
bool myCircularDequeInsertFront(MyCircularDeque* q, int v) {
    if (q->sz == q->k) return false;
    q->f = (q->f - 1 + q->k) % q->k;
    q->a[q->f] = v;
    if (!q->sz) q->r = q->f;
    q->sz++;
    return true;
}
bool myCircularDequeInsertLast(MyCircularDeque* q, int v) {
    if (q->sz == q->k) return false;
    q->r = (q->r + 1) % q->k;
    q->a[q->r] = v;
    if (!q->sz) q->f = q->r;
    q->sz++;
    return true;
}
bool myCircularDequeDeleteFront(MyCircularDeque* q) {
    if (!q->sz) return false;
    q->f = (q->f + 1) % q->k;
    q->sz--;
    return true;
}
bool myCircularDequeDeleteLast(MyCircularDeque* q) {
    if (!q->sz) return false;
    q->r = (q->r - 1 + q->k) % q->k;
    q->sz--;
    return true;
}
int myCircularDequeGetFront(MyCircularDeque* q) {
    return q->sz ? q->a[q->f] : -1;
}
int myCircularDequeGetRear(MyCircularDeque* q) {
    return q->sz ? q->a[q->r] : -1;
}
bool myCircularDequeIsEmpty(MyCircularDeque* q) {
    return q->sz == 0;
}
bool myCircularDequeIsFull(MyCircularDeque* q) {
    return q->sz == q->k;
}
void myCircularDequeFree(MyCircularDeque* q) {
    free(q->a);
    free(q);
}