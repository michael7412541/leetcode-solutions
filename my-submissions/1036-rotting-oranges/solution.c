typedef struct {
    int x;
    int y;
} Point;
int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int count = 0, sum = 0, size = 0, min = 0, head, tail = -1, x1, y1;
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    Point queue[1000], cur;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridColSize[i]; j++){
            if(grid[i][j] == 1)
                sum++;
            else if(grid[i][j] == 2){
                count++;
                sum++;
                queue[++tail] = (Point){i, j};
            }
        }
    }
    if(sum == 0)
        return 0;

    head = -1;
    while(head < tail){
        if(count == sum)
            return min;

        size = tail - head;

        for(int i = 0; i < size; i++){
            cur = queue[++head];
            ///printf("head = %d, tail = %d\n", head, tail);
            for(int k = 0; k < 4; k++){
                x1 = cur.x + dir[k][0];
                y1 = cur.y + dir[k][1];
                if(x1 >= 0 && x1 < gridSize && y1 >= 0 && y1 < gridColSize[0] && grid[x1][y1] == 1){
                    grid[x1][y1] = 2;
                    queue[++tail] = (Point){x1, y1};
                    count++;
                }
            }
        }
        printf("\n");


        min++;
    }
    
    //return -1;
    return count == sum ? min : -1;
    //最後一輪感染完：

//count == sum

//但 while 結束了。

//這時候直接 return -1 不夠保險。

}
