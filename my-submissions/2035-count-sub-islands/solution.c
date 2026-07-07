int dfs(int x, int y, int x_size, int y_size, int **grid1, int **grid2){
    if(x >= x_size || y >= y_size || x < 0 || y < 0)
        return 0;

    if(grid2[x][y] == 0)
        return 0;
    
    grid2[x][y] = 0;
    

    int up = dfs(x + 1, y, x_size, y_size, grid1, grid2); 
    int dn = dfs(x - 1, y, x_size, y_size, grid1, grid2); 
    int right = dfs(x, y + 1, x_size, y_size, grid1, grid2); 
    int left = dfs(x, y - 1, x_size, y_size, grid1, grid2); 

    if(grid1[x][y] == 0)
        return -1;
    else if(up == -1 || dn == -1 || right == -1 || left == -1)
        return -1;
    else
        return up + dn + right + left + 1;

}
int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, int** grid2, int grid2Size, int* grid2ColSize) {
    int area = 0, answer = 0;
    for(int i = 0; i < grid1Size; i++){
        for(int j = 0; j < grid1ColSize[i]; j++){
            if(grid2[i][j] != 0){
                area = dfs(i, j, grid1Size, grid1ColSize[i], grid1, grid2);
                if(area > 0)
                    answer++;
            }
        }
    }
    return answer;
}
