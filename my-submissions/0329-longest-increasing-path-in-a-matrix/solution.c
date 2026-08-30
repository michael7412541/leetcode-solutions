int max = 0;
int max_l(int a, int b, int c, int d){
    if(a >= b && a >= c && a >= d) return a;
    if(b >= c && b >= a && b >= d) return b;
    if(c >= b && c >= a && c >= d) return c;
    return d;
}
int dfs(int** matrix, int m, int n, int x, int y, int **dp) {
    if(x >= m || y >= n || x < 0 || y < 0)
        return 0;
    
    if(dp[x][y] != -1)
        return dp[x][y];
    int a = 0 ,b = 0 ,c = 0, d = 0;

    if(x + 1 < m && matrix[x][y] < matrix[x+1][y])
        a = dfs(matrix, m, n, x + 1, y, dp);
    if(x - 1 >= 0 && matrix[x][y] < matrix[x-1][y])
        b = dfs(matrix, m, n, x - 1, y, dp);
    if(y + 1 < n && matrix[x][y] < matrix[x][y+1])
        c = dfs(matrix, m, n, x, y + 1, dp);
    if(y - 1 >= 0 && matrix[x][y] < matrix[x][y-1])
        d = dfs(matrix, m, n, x, y - 1, dp);

    
    dp[x][y] = max_l(a, b, c, d) + 1;
    if(dp[x][y] > max)
        max = dp[x][y];
    return dp[x][y]; 
    
     
}
int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    int **dp = malloc(sizeof(int*) * matrixSize * matrixColSize[0]);
    for(int i = 0; i < matrixSize; i++){
        dp[i] = malloc(sizeof(int) * matrixColSize[i]);
        for(int j = 0; j < matrixColSize[i]; j++){
            dp[i][j] = -1;
        }
    }
    max = 0;
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixColSize[i]; j++){
        dfs(matrix, matrixSize, matrixColSize[i], i, j, dp);
        }
    }
    
    return max;
}
