/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.
Input Format:
- First line contains integer N
- Second line contains N space-separated integers
Output Format:
- Print the reversed queue
Example:
Input:
5
10 20 30 40 50
Output:
50 40 30 20 10*/

#include <stdio.h>
int main() {
    int n, i;
    scanf("%d", &n);
    int queue[n], stack[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }
    for(i = 0; i < n; i++) {
        stack[i] = queue[i];
    }
    for(i = n - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    return 0;
}