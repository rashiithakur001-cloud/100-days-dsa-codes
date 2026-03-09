/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]*/

int* productExceptSelf(int* a, int size, int* retSize) {
    int* ans = (int*)malloc(size * sizeof(int));
    *retSize = size;

    int left = 1;
    for (int i = 0; i < size; i++) {
        ans[i] = left;
        left *= a[i];
    }

    int right = 1;
    for (int i = size - 1; i >= 0; i--) {
        ans[i] *= right;
        right *= a[i];
    }
     return ans;
}