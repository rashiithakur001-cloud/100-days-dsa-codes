/* Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

*/
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int freq[1001] = {0};
// Count frequency of nums1
for (int i = 0; i < nums1Size; i++) {
    freq[nums1[i]]++;
    }
// Allocate result array (max possible size = smaller array)
int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    *returnSize = 0;
// intersection
for (int i = 0; i < nums2Size; i++) {
    if (freq[nums2[i]] > 0) {
result[*returnSize] = nums2[i];
    (*returnSize)++;
    freq[nums2[i]]--;
    }
}
    return result;
}