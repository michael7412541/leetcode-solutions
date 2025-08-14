/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct {
    int x;
    int y;
} Point;

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    Point *queue = (Point*)malloc(sizeof(Point) * matSize * matColSize[0]);
    int i = 0, j = 0;
    //int **map = (int**)malloc(sizeof(int*) * matSize * matColSize[0]);
    int **map = (int**)malloc(sizeof(int*) * matSize );
    *returnColumnSizes = (int*)malloc(sizeof(int) * matSize);//*
    *returnSize = matSize;
    for(i = 0 ; i < matSize; i++) {
        map[i] = (int*)calloc(matColSize[0], sizeof(int));
        (*returnColumnSizes)[i] = matColSize[0];
        for(j = 0; j < matColSize[0]; j++) {
            if(mat[i][j] != 0)
                map[i][j] = matSize * matColSize[0] + 1;
        }
    }
    int head = 0, tail = 0;
    for(i = 0 ; i < matSize; i++) {
        for(j = 0; j < matColSize[0]; j++) {
            if(mat[i][j] == 0) {
                queue[tail++] = (Point){i,j};
             }
        }
    }
    
    //tail 永遠指向「下一個空位」，不是最後一個元素
    //head 永遠指向「下一個要出隊的元素」
    //queue 的有效元素是 [head, tail-1]
    
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    while(head < tail) {
        Point p;
        int tx, ty;
        p = queue[head++];// 把每個0拿出來擴散
        
        for(int k = 0; k < 4; k++) {
            tx = p.x + dir[k][0];
            ty = p.y + dir[k][1];
            if(tx >= 0 && ty >= 0 && tx < matSize && ty < matColSize[0]) {
                if(map[tx][ty] > map[p.x][p.y] + 1) {
                    map[tx][ty] = map[p.x][p.y] + 1;
                    queue[tail++] = (Point){tx, ty};
                }
                
            }
        }
    }
    
    free(queue);
    
    
    return map;
    
}
