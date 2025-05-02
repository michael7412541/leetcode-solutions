/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** answer = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int)); 
    int i = 0, j = 0;
    
    for(i = 1; i <= numRows; i++)
    {
        answer[i-1] = (int*)malloc(i * sizeof(int));
        (*returnColumnSizes)[i-1] = i;
        for(j = 0; j < i; j++)
        {
            if(i == 1)
                answer[i-1][j] = 1;
            else if(i == 2)
                answer[i-1][j] = 1;
            else if(j == 0 || j == i - 1)
                answer[i-1][j] = 1;
            else
                answer[i-1][j] = answer[i-2][j] + answer[i-2][j-1];
            printf(" %d", answer[i-1][j]);
        }
        printf(" \n");
    }
    
    
    *returnSize = numRows;
    
    return answer;
}
