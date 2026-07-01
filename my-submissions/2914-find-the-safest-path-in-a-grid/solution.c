typedef struct {
    int x;
    int y;
} Point;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 修正：將 visited 改為動態傳入，徹底避免區域陣列在多測資下的編譯器優化殘留問題
int isValid(int mid, int n, int map[][n], int visited[][n]) {
    if (map[0][0] < mid || map[n - 1][n - 1] < mid) {
        return 0;
    }

    // 每次驗證前，精準將 visited 矩陣清空
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    
    // 建立一個足夠大且安全的 Queue
    Point* queue = (Point*)malloc(n * n * sizeof(Point));
    int head = 0, tail = 0;

    queue[tail++] = (Point){0, 0};
    visited[0][0] = 1;

    while (head < tail) {
        Point curr = queue[head++];

        if (curr.x == n - 1 && curr.y == n - 1) {
            free(queue);
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                // 必須嚴格限制踩到的格子安全係數一定要大於等於 mid
                if (!visited[nx][ny] && map[nx][ny] >= mid) {
                    visited[nx][ny] = 1;
                    queue[tail++] = (Point){nx, ny};
                }
            }
        }
    }
    free(queue);
    return 0; 
}

int maximumSafenessFactor(int** grid, int gridSize, int* gridColSize){
    int n = gridSize;
    int map[n][n];
    int visited[n][n]; // 用於二分搜尋驗證的矩陣
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    // 初始化 map 矩陣
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = -1;
        }
    }
    
    Point* queue = (Point*)malloc(n * n * sizeof(Point));
    int head = 0, tail = 0; 
    
    // 找出所有小偷作為起點
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1) {
                queue[tail++] = (Point){i, j};
                map[i][j] = 0;
            }
        }
    }
    
    // 多源 BFS 計算曼哈頓距離
    while(head < tail){
        Point cur = queue[head++];
        for(int k = 0; k < 4; k++){
            int x1 = cur.x + dir[k][0];
            int y1 = cur.y + dir[k][1];
            if(x1 < n && x1 >= 0 && y1 < n && y1 >= 0){
                if(map[x1][y1] == -1) {
                    map[x1][y1] = map[cur.x][cur.y] + 1;
                    queue[tail++] = (Point){x1, y1};
                }
            }
        }
    }
    free(queue);
    
    // 二分搜尋：上限精準鎖定在起點的安全係數
    int ans = 0, low = 0, high = map[0][0];
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(isValid(mid, n, map, visited)){
            ans = mid;
            low = mid + 1; // 嘗試找看看有沒有更安全的路線
        } else {
            high = mid - 1; // 太危險了，放寬安全限制
        }
    }
    return ans;
}
