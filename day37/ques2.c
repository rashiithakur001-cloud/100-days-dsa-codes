/*You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.
You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.
Implement the KthLargest class:
KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
Example 1:
Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output: [null, 4, 5, 5, 8, 8]
Explanation:
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8
Example 2:
Input:
["KthLargest", "add", "add", "add", "add"]
[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]
Output: [null, 7, 7, 7, 8]
Explanation:
KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
kthLargest.add(2); // return 7
kthLargest.add(10); // return 7
kthLargest.add(9); // return 7
kthLargest.add(9); // return 8*/
#include <stdlib.h>
typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void heapup(KthLargest* obj, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (obj->heap[p] <= obj->heap[i]) break;
        swap(&obj->heap[p], &obj->heap[i]);
        i = p;
    }
}
void heapdown(KthLargest* obj, int i) {
    while (1) {
        int smallest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < obj->size && obj->heap[l] < obj->heap[smallest])
            smallest = l;
        if (r < obj->size && obj->heap[r] < obj->heap[smallest])
            smallest = r;
        if (smallest == i) break;
        swap(&obj->heap[i], &obj->heap[smallest]);
        i = smallest;
    }
}
void push(KthLargest* obj, int val) {
    obj->heap[obj->size] = val;
    heapup(obj, obj->size);
    obj->size++;
}
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = malloc(sizeof(KthLargest));
    obj->heap = malloc(sizeof(int) * k);
    obj->size = 0;
    obj->k = k;
    for (int i = 0; i < numsSize; i++) {
        if (obj->size < k) {
            push(obj, nums[i]);
        } else if (nums[i] > obj->heap[0]) {
            obj->heap[0] = nums[i];
            heapdown(obj, 0);
        }
    }
    return obj;
}
int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        push(obj, val);
    } 
    else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapdown(obj, 0);
    }
    return obj->heap[0];
}
void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}