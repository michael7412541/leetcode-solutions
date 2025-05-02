/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* answer = (int*)malloc(matrixSize * matrixColSize[0] * sizeof(int));
    int top = 0, bottom = matrixSize - 1, left = 0, right = matrixColSize[0] - 1;
    int i = 0, j = 0, count = 0;
    while(top <= bottom && left <= right)
    {
    if(top <= bottom && left <= right){
        for(i = top, j = left; j <= right; j++)
        {
            answer[count] = matrix[i][j];
            printf(" %d", answer[count]);
            count++;
        }
        top++;}
    if(top <= bottom && left <= right){
        for(j = right, i = top; i <= bottom; i++)
        {
            answer[count] = matrix[i][j];
            printf(" %d", answer[count]);
            count++;
        }
        right--;}
    if(top <= bottom && left <= right){
        for(j = right, i = bottom; j >= left; j--)
        {
            answer[count] = matrix[i][j];
            printf(" %d", answer[count]);
            count++;
        }
        bottom--;}
    if(top <= bottom && left <= right){
        for(j = left, i = bottom; i >= top; i--)
        {
            answer[count] = matrix[i][j];
            printf(" %d", answer[count]);
            count++;
        }
        left++;}
       
    }
    *returnSize = count;
    return answer;
}
