/*Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the matrix

Output:
- Print "Symmetric Matrix" if the given matrix is symmetric
- Otherwise, print "Not a Symmetric Matrix"

Example:
Input:
3 3
1 2 3
2 4 5
3 5 6

Output:
Symmetric Matrix
Explanation:
The matrix is square (3 × 3) and for every i and j, element[i][j] = element[j][i].
*/

#include <stdio.h>
int main() {
 int m, n;
 scanf("%d %d", &m, &n);
int matrix[m][n];
 // Input elements
 for(int i = 0; i < m; i++) {
   for(int j = 0; j < n; j++) {
    scanf("%d", &matrix[i][j]);
 }
    }
 // Check if matrix is square
    if(m != n) {
    printf("Not a Symmetric Matrix");
      return 0;
 }
 // Check symmetry condition
for(int i = 0; i < m; i++) {
  for(int j = 0; j < n; j++) {
if(matrix[i][j] != matrix[j][i]) {
  printf("Not a Symmetric Matrix");
    return 0;
 }
    }
}
printf("Symmetric Matrix");
    return 0;
}