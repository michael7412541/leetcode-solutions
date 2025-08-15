typedef struct {
    int x;
    int y;
} Point;

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int **record = (int**)malloc(sizeof(int*)*gridSize);
    int i = 0, j = 0, k, count = 0, head = 0, tail = 0;
    Point *queue = (Point*)malloc(sizeof(Point)*gridSize*gridColSize[0]);
    
    for(i = 0; i < gridSize; i++) {
        record[i] = (int*)calloc(gridColSize[0], sizeof(int));
    }
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < gridColSize[0]; j++) {
            if(grid[i][j] == '1' && record[i][j] == 0) {
                record[i][j] = 1;
                queue[tail++] = (Point){i,j};
                count++;
                while(head < tail) {
                    Point p;
                    p = queue[head++];
                    
                    for(k = 0; k < 4; k++) {
                        int r = p.x + dir[k][0];
                        int c = p.y + dir[k][1];
                        if(r >= 0 && r < gridSize && c >= 0 && c < gridColSize[0] && 
                        grid[r][c] == '1' && record[r][c] == 0) {
                            record[r][c] = 1;
                            queue[tail++] = (Point){r,c};
                        }
                        
                    }
                }
                
            }
        }
    }
   for(i = 0; i < gridSize; i++) {
        free(record[i]);
    }
    
    free(record);
    free(queue);
    return count;
}
