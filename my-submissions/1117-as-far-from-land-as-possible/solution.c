typedef struct {
    int x;
    int y;
} Point;
int maxDistance(int** grid, int gridSize, int* gridColSize) {
    if(grid == NULL || gridSize == 0){
        return 0;
    }
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int **answer = malloc(sizeof(int*) * gridSize);
    Point queue[10000], cur;
    int head = -1, tail = -1, count, x1, y1;

    for(int i = 0; i < gridSize; i++){
        answer[i] = malloc(sizeof(int) * gridColSize[i]);
        for(int j = 0; j < gridColSize[i]; j++){
            answer[i][j] = -1;
            if(grid[i][j] == 1){
                queue[++tail] = (Point){i,j};
                answer[i][j] = 0;
            }
        }
    }
    if(tail == -1 || tail == gridSize * gridColSize[0]  -1)
        return -1;
    while(head < tail){
        cur = queue[++head];
        for(int k = 0; k < 4; k++){
            x1 = cur.x + dir[k][0];
            y1 = cur.y + dir[k][1];
            if(x1 >= 0 && x1 < gridSize && y1 >= 0 && y1 < gridColSize[0] && answer[x1][y1] == -1){
                answer[x1][y1] = answer[cur.x][cur.y] + 1; 
                queue[++tail] = (Point){x1,y1};
            }
                
        }
    }
    int max = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridColSize[i]; j++){
           if(answer[i][j] > max)
            max = answer[i][j];
        }
    }

    return max;
}
