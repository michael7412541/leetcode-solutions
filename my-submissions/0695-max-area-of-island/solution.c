typedef struct {
    int x;
    int y;
} Point;
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int **record = malloc(sizeof(int*)*gridSize);
    int i, j, size, answer = 0, head = -1, tail = -1, x1, y1;
    int dir[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0,-1}};
    for(i = 0; i < gridSize; i++){
        record[i] = malloc(sizeof(int)*gridColSize[i]);
    }
    // record init to 0
    for(i = 0; i < gridSize; i++){
        for(j = 0; j < gridColSize[i]; j++){
            record[i][j] = 0;
        }
    }
    
    Point queue[1000000], cur;
    
    for(i = 0; i < gridSize; i++){
        for(j = 0; j < gridColSize[i]; j++){
            size = 0;
            if(record[i][j] != 1 && grid[i][j] == 1){
                head = -1;
                tail = -1;
                queue[++tail] = (Point){i, j};
                size = 0;
                record[i][j] = 1; 
                while(head < tail){
                    cur = queue[++head];
                    record[cur.x][cur.y] = 1; 
                    for(int k = 0; k < 4; k++){
                        x1 = cur.x + dir[k][0];
                        y1 = cur.y + dir[k][1];
                        if(x1 >= 0 && x1 < gridSize && 
                           y1 >= 0 && y1 < gridColSize[0] && 
                           record[x1][y1] != 1 && grid[x1][y1] == 1){
                            record[x1][y1] = 1; 
                            queue[++tail] = (Point){x1, y1};
                        }
                    }
                    size++;
                }
                if(size > answer)
                    answer = size;
            }
        }
    }
    return answer;
}
