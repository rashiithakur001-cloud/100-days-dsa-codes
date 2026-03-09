/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/

#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int n;
    int arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    int l = 0, r = n - 1;
    int bestSum = arr[l] + arr[r];
    int x = arr[l], y = arr[r];
while (l < r) {
    int sum = arr[l] + arr[r];
if (abs(sum) < abs(bestSum)) {
    bestSum = sum;
    x = arr[l];
    y = arr[r];
        }
if (sum < 0)
   l++;
 else
  r--;
    }
printf("%d %d\n", x, y);
    return 0;
}