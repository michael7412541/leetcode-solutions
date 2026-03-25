/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int left = 0, right = matrixColSize[0] - 1, up = 0, down = matrixSize - 1;
    int i = 0, j = 0, count = 0;
    int *answer = malloc(sizeof(int) * matrixSize * matrixColSize[0]);
    
    while(left <= right && up <= down){
        for(i = up, j = left; j <= right; j++)
            answer[count++] = matrix[i][j];
        
        for(i = up + 1, j = right ; i <= down; i++)
            answer[count++] = matrix[i][j];
        
        if (up < down) {
        for(i = down, j = right - 1; j >= left; j-- )
            answer[count++] = matrix[i][j];
        }
        if (left < right){
        for(i = down - 1, j = left; i > up; i--)
            answer[count++] = matrix[i][j];
        }
        up++;
        down--;
        left++;
        right--;
    }
    *returnSize = matrixSize * matrixColSize[0];
    return answer;
}
