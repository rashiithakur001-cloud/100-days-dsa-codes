/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]*/

void setZeroes(int grid[200][200], int rows, int cols) {
int firstRowZero = 0;
    int firstColZero = 0;
for (int r = 0; r < rows; r++) {
    if (grid[r][0] == 0) {
    firstColZero = 1;
    break;
    }
}
for (int c = 0; c < cols; c++) {
   if (grid[0][c] == 0) {
    firstRowZero = 1;
    break;
}
    }
for (int r = 1; r < rows; r++) {
 for (int c = 1; c < cols; c++) {
   if (grid[r][c] == 0) {
    grid[r][0] = 0;
    grid[0][c] = 0;
 }
   }
    }
for (int r = 1; r < rows; r++) {
  if (grid[r][0] == 0) {
    for (int c = 1; c < cols; c++) {
    grid[r][c] = 0;
 }
   }
    }
for (int c = 1; c < cols; c++) {
 if (grid[0][c] == 0) {
  for (int r = 1; r < rows; r++) {
    grid[r][c] = 0;
   }
 }
    }
if (firstColZero) {
    for (int r = 0; r < rows; r++) {
    grid[r][0] = 0;
}
    }
if (firstRowZero) {
for (int c = 0; c < cols; c++) {
    grid[0][c] = 0;
}
    }
    return 0;
}