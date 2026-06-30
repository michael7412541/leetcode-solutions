int helper(int **matrix, int x, int y, int x_size, int y_size, int **visited, int target){
    if(x >= x_size || y >= y_size || x < 0 || y < 0)
        return 0;

    if(matrix[x][y] <= target)
        return 0;

    if(visited[x][y] != -1)
        return visited[x][y] + 1;
    
    visited[x][y] = 0;
    int max = 0;
    int up = helper(matrix, x + 1, y, x_size, y_size, visited, matrix[x][y]);
    int dn = helper(matrix, x - 1, y, x_size, y_size, visited, matrix[x][y]);
    int right = helper(matrix, x, y + 1, x_size, y_size, visited, matrix[x][y]);
    int left = helper(matrix, x, y - 1, x_size, y_size, visited, matrix[x][y]);

    if(max < up) max = up;
    if(max < dn) max = dn;
    if(max < left) max = left;
    if(max < right) max = right;

    visited[x][y] = max;
    return max + 1;
}
int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    int count = 0, answer = 0;
    int **visited = malloc(sizeof(int*) * matrixSize);

    for(int i = 0; i < matrixSize; i++){
        visited[i] = malloc(sizeof(int) * matrixColSize[i]);
        for(int j = 0; j < matrixColSize[i]; j++){
            visited[i][j] = -1;
        }
    }

    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixColSize[i]; j++){
            count = helper(matrix, i, j, matrixSize, matrixColSize[i], visited, -1);
            if(count > answer)
                answer = count;
        }
    }

   
    free(visited);
    return answer;
}
