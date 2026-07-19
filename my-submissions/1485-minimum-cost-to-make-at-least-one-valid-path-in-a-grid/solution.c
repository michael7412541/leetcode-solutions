typedef struct{
    int x;
    int y;
    int dist;
} Point;
int minCost(int** grid, int gridSize, int* gridColSize) {
    int front = 15000, back = 15000, newDist = 0;
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int dist[gridSize][gridColSize[0]];
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            dist[i][j]=INT_MAX;
        }
    }
    Point cur, queue[30000];
    queue[front].x = 0;
    queue[front].y = 0;
    queue[front].dist = 0;
    back++;
    dist[0][0] = 0;
    while(front < back){
        cur = queue[front++];//pop_front

        if(cur.dist > dist[cur.x][cur.y])
            continue;

        for(int k = 0; k < 4; k++){
            int nx = cur.x + dir[k][0];
            int ny = cur.y + dir[k][1];
            if(ny >= gridColSize[0] || ny < 0 || nx >= gridSize || nx < 0)
                continue;
            

            if(grid[cur.x][cur.y]-1 == k){
                //push_front();
                newDist = dist[cur.x][cur.y];
                if(newDist < dist[nx][ny]){
                    dist[nx][ny] = newDist;
                    queue[--front] = (Point){nx, ny, newDist};
                }
            }
            else{
                //push_back();
                newDist = dist[cur.x][cur.y] + 1;
                if(newDist < dist[nx][ny]){
                    dist[nx][ny] = newDist;
                    queue[back++] = (Point){nx, ny, newDist};
                }
            }
            
        }
    }
    return dist[gridSize-1][gridColSize[0]-1];
}
