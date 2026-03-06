/* Given an m x n matrix, return all elements of the matrix in spiral order.
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/ 
#include <stdlib.h>
int* spiralOrder(int** grid, int rowCount, int* colCount, int* outputSize) {
    if (rowCount == 0 || colCount[0] == 0) {
        *outputSize = 0;
        return NULL;
    }
int totalRows = rowCount;
    int totalCols = colCount[0];
int* outputArray = (int*)malloc(sizeof(int) * totalRows * totalCols);
    int position = 0;
int startRow = 0;
    int endRow = totalRows - 1;
    int startCol = 0;
    int endCol = totalCols - 1;
while (startRow <= endRow && startCol <= endCol) {
// Traverse Left → Right
for (int col = startCol; col <= endCol; col++)
outputArray[position++] = grid[startRow][col];
startRow++;
// Traverse Top → Bottom
for (int row = startRow; row <= endRow; row++)
 outputArray[position++] = grid[row][endCol];
    endCol--;
// Traverse Right → Left
if (startRow <= endRow) {
 for (int col = endCol; col >= startCol; col--)
    outputArray[position++] = grid[endRow][col];
    endRow--;
 }
// Traverse Bottom → Top
if (startCol <= endCol) {
for (int row = endRow; row >= startRow; row--)
    outputArray[position++] = grid[row][startCol];
        startCol++;
 }
    }
 *outputSize = position;
    return outputArray;
}