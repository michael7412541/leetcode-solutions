typedef struct {
    int x;
    int y;
}Point;
int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int answer = 0, dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}, count = 0;
    Point cur;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridColSize[i]; j++){
            if(grid[i][j] == 1){
                count = 0;
                for(int k = 0; k < 4; k++){
                    cur.x = i + dir[k][0];
                    cur.y = j + dir[k][1];
                    
                    if(cur.x >= 0 && cur.x < gridSize && cur.y >= 0 && cur.y < gridColSize[i] && grid[cur.x][cur.y] == 1)
                    count++;  
                }
                //printf("(%d, %d) +%d\n", i, j, 4-count);
                answer += (4 - count); 
            }
        }
    }
    return answer;
}
