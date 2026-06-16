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
    if(mat == NULL || matSize == 0){
        return NULL;
    }
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int **answer = malloc(sizeof(int*) * matSize);
    Point queue[10000], cur;
    int head = -1, tail = -1, count, x1, y1;

    *returnSize = matSize;
    *returnColumnSizes = malloc(sizeof(int) * matSize);
    for(int i = 0; i < matSize; i++){
        answer[i] = malloc(sizeof(int) * matColSize[i]);
        (*returnColumnSizes)[i] = matColSize[i];
        for(int j = 0; j < matColSize[i]; j++){
            answer[i][j] = -1;
            if(mat[i][j] == 0){
                queue[++tail] = (Point){i,j};
                answer[i][j] = 0;
            }
        }
    }

    while(head < tail){
        cur = queue[++head];
        for(int k = 0; k < 4; k++){
            x1 = cur.x + dir[k][0];
            y1 = cur.y + dir[k][1];
            if(x1 >= 0 && x1 < matSize && y1 >= 0 && y1 < matColSize[0] && answer[x1][y1] == -1){
                answer[x1][y1] = answer[cur.x][cur.y] + 1; 
                queue[++tail] = (Point){x1,y1};
            }
                
        }
    }
    
    return answer;
}
