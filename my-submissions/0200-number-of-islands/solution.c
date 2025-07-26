int numIslands(char** grid, int gridSize, int* gridColSize) {
    
    int i = 0, j = 0, k = 0, x, y, cx, cy, top = -1,count = 0;
    int **stack = (int**)malloc(sizeof(int*)*gridSize* gridColSize[0]);
    int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0, -1}};
    for(i = 0; i < gridSize* gridColSize[0]; i++)
            stack[i] = (int*)malloc(sizeof(int)*2);
    
    
    for(i = 0; i < gridSize; i++){
        for(j = 0; j < gridColSize[i]; j++){
            if(grid[i][j] == '1'){
                top++;
                stack[top][0] = i;
                stack[top][1] = j;
                count++;
                while(top >= 0){
                    cx = stack[top][0];
                    cy = stack[top][1];
                    grid[cx][cy] = '0';
                    top--;
                    
                    for(k = 0; k < 4; k++){
                        x = cx + dir[k][0];
                        y = cy + dir[k][1];
                        if(x >= 0 && x < gridSize && y >= 0 && y < gridColSize[x] && grid[x][y] == '1'){
                            top++;
                            stack[top][0] = x;
                            stack[top][1] = y;
                        }
                    }
                }
                    
                
            }
        }
    }
    
    
    for(i = 0; i < gridSize * gridColSize[0]; i++)
    free(stack[i]);
    free(stack);
    
    
    return count;
    
}
