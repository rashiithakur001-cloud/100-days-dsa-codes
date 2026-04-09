/* There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.
Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3 */
#include <stdio.h>
#define MAX 200
void dfs(int city, int n, int isConnected[MAX][MAX], int visited[]) {
    visited[city] = 1;
for (int i = 0; i < n; i++) {
  if (isConnected[city][i] == 1 && !visited[i]) {
  dfs(i, n, isConnected, visited);
}
    }
}
int findCircleNum(int isConnected[MAX][MAX], int n) {
    int visited[MAX] = {0};
    int provinces = 0;
for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, isConnected, visited);
            provinces++;
        }
    }
    return provinces;
}
int main() {
    int n;
    scanf("%d", &n);
 int isConnected[MAX][MAX];
// Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }
int result = findCircleNum(isConnected, n);
    printf("%d", result);
 return 0;
}