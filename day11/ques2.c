/*Given a 2D integer array matrix, return the transpose of matrix. 
The transpose of a matrix is the matrix flipped over its main diagonal,
switching the matrix's row and column indices.*/

int** transpose(int** matrix, int matrixSize, int* matrixColSize, 
 int* returnSize, int** returnColumnSizes) {
 int rows = matrixSize;              
 int cols = matrixColSize[0];        
    *returnSize = cols;
*returnColumnSizes = (int*)malloc(cols * sizeof(int));
 for (int i = 0; i < cols; i++) {
    (*returnColumnSizes)[i] = rows;
    }
int** res = (int**)malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
     res[i] = (int*)malloc(rows * sizeof(int));
 }  
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      res[j][i] = matrix[i][j];
 }
    }
    return res;
}