int dfs(int **grid, int x, int y, int x_size, int y_size){
    if(x >= x_size || y >= y_size || x < 0 || y < 0)
        return 0;
    
    if(grid[x][y] == 0)
        return 0;
    grid[x][y] = 0;
    int up = dfs(grid, x + 1, y, x_size, y_size);
    int down = dfs(grid, x - 1, y, x_size, y_size);
    int left = dfs(grid, x, y + 1, x_size, y_size);
    int right = dfs(grid, x, y - 1, x_size, y_size);
    
    return up + down + left + right + 1;

}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int answer = 0, area;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridColSize[i]; j++){
            if(grid[i][j] == 1){
                area = dfs(grid, i, j, gridSize, gridColSize[i]);
                if(area > answer)
                    answer = area;
            }
               
        }
    }
    return answer;
}
