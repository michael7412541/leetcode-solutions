/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int* answer = (int*)malloc(matSize*matColSize[0]*sizeof(int));
    int i = 0, j = 0, count = 0;
    int change = 0;
    for(i = 0; i <= matSize + matColSize[0] - 2; i++)
    {
        if(change == 0)
        {
            for(j = 0; j <= i ; j++)
            {
                if(i-j < matSize && j < matColSize[0])
                {
                    answer[count] = mat[i-j][j];
                    printf("mat = %d",  mat[i-j][j]);
                    printf("answer = %d\n",  answer[count]);
                    count++;
                }
            }
            change = 1;
        }
        else
        {
            for(j = i; j >= 0 ;j--)
            {
                if(i-j < matSize && j < matColSize[0])
                {
                    answer[count] = mat[i-j][j];
                    printf("mat = %d",  mat[i-j][j]);
                    printf("answer = %d\n",  answer[count]);
                    count++;
                }
            }
            change = 0;
        }
    }
    *returnSize = matSize*matColSize[0];
    return answer;
}
