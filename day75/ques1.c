/*Problem Statement:Given an array of integers containing both positive and negative values,
 find the length of the longest contiguous subarray whose sum is equal to zero.*/

#include <stdio.h>

#define MAX 1000

int maxLenZeroSum(int arr[], int n) {
    int prefixSum = 0;
    int maxLen = 0;

    // Hash map using arrays (for simplicity)
    int map[2001];   // to handle negative sums
    for (int i = 0; i < 2001; i++) {
        map[i] = -2; // -2 means not visited
    }

    int offset = 1000; // shift to handle negative indices

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum = 0 from start
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        // Case 2: prefix sum seen before
        if (map[prefixSum + offset] != -2) {
            int prevIndex = map[prefixSum + offset];
            int len = i - prevIndex;
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            // store first occurrence
            map[prefixSum + offset] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLenZeroSum(arr, n));

    return 0;
}