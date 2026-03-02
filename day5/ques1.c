/* Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)
Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60
Output:
10 15 20 25 30 40 50 60 70
*/

#include <stdio.h>
int main() {
    int p, q, i = 0, j = 0;
 // Read size of first log
    scanf("%d", &p);
    int A[p];
    for(int k = 0; k < p; k++)
        scanf("%d", &A[k]);
// Read size of second log
    scanf("%d", &q);
    int B[q];
    for(int k = 0; k < q; k++)
      scanf("%d", &B[k]);
// Merge both logs
while(i < p && j < q) {
   if(A[i] <= B[j]) {
     printf("%d ", A[i]);
    i++;
} else {
    printf("%d ", B[j]);
    j++;
        }
    }
// Print remaining elements
    while(i < p) {
    printf("%d ", A[i]);
    i++;
    }
while(j < q) {
    printf("%d ", B[j]);
      j++;
    }
return 0;
}