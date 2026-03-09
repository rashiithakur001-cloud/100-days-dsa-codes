/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/

#include <stdio.h>
void rev(int a[], int l, int r) {
    while (l < r) {
        int t = a[l];
        a[l] = a[r];
        a[r] = t;
        l++;
        r--;
    }
}
int main() {
    int len, k;
    int nums[100];
scanf("%d", &len);
    for (int i = 0; i < len; i++)
    scanf("%d", &nums[i]);
 scanf("%d", &k);
    k = k % len;
    rev(nums, 0, len - 1);
    rev(nums, 0, k - 1);
    rev(nums, k, len - 1);
for (int i = 0; i < len; i++) {
    printf("%d", nums[i]);
 if (i < len - 1) printf(" ");
 }
    return 0;
}