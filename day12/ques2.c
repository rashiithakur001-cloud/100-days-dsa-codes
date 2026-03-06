/*
Problem: Toeplitz Matrix
Given an m x n matrix, return true if the matrix is Toeplitz.
Otherwise, return false.
A matrix is Toeplitz if every diagonal from top-left to bottom-right
has the same elements.

Input:
- matrix: 2D integer array of size m x n
Output:
- Return true if the matrix is Toeplitz
- Return false otherwise
Example 1:
Input:
matrix = [
  [1, 2, 3, 4],
  [5, 1, 2, 3],
  [9, 5, 1, 2]
]
Output:
true
Explanation:
All diagonals from top-left to bottom-right contain the same elements.
*/
#include<stdbool.h>
bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
 int rows = matrixSize;
 int cols = matrixColSize[0];
for(int i = 1; i < rows; i++) {
   for(int j = 1; j < cols; j++) {
if(matrix[i][j] != matrix[i-1][j-1]) {
   return false;
}
    }
}
  return true;
}