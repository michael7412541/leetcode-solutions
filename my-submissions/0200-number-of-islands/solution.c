typedef struct {
    int x;
    int y;
} Point ;
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int **record = malloc(sizeof(int*) * gridSize);
    for(int i = 0; i < gridSize; i++){
        record[i] = malloc(sizeof(int) * gridColSize[i]);
        for(int j = 0; j < gridColSize[i]; j++){
            record[i][j] = 0;
        }
    }
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}, answer = 0, head = -1, tail = -1, x1, y1;
    Point queue[10000], cur;

    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridColSize[i]; j++){
            
            if(record[i][j] == 0 && grid[i][j] == '1'){
                //printf("find\n");
                head = -1;
                tail = -1;
                record[i][j] = 1;
                queue[++tail] = (Point){i, j};

                while(head < tail){
                    cur = queue[++head];
                    for(int k = 0; k < 4; k++){
                        x1 = cur.x + dir[k][0];
                        y1 = cur.y + dir[k][1];
                        if(x1 >= 0 && x1 < gridSize && y1 >= 0 && y1 < gridColSize[0] && grid[x1][y1] == '1' && record[x1][y1] == 0){
                            record[x1][y1] = 1;
                            queue[++tail] = (Point){x1, y1};
                        }
                    }
                }
                answer++;
                
            }
            
        }
    }

    return answer;
}
