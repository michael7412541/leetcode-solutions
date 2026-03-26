/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int dir = 1, count = 0, j = 0;
    int *answer = malloc(sizeof(int) * matColSize[0] * matSize);
    for(int k = 0; k < matSize + matColSize[0] - 1; k++){
        if(dir==0){
        for(int i = 0; i <= k; i++){
            j = k - i;
            if(i < matSize && j < matColSize[0])
                answer[count++] = mat[i][j];
        }
            dir = 1;
        }
        else{
            for(int i = k; i >= 0; i--){
            j = k - i;
            if(i < matSize && j < matColSize[0])
                answer[count++] = mat[i][j];
        }
            dir = 0;
        }
            
        
        
    }
    *returnSize = matSize * matColSize[0];
    
    return answer;
}
