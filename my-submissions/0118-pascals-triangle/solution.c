/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    int **answer = malloc(sizeof(int*) * (*returnSize));
    
    // ⭐ 補這一行
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    for(int i = 0; i < numRows; i++){
        (*returnColumnSizes)[i] = i + 1;
        answer[i] = malloc(sizeof(int) * (i + 1));
    }
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < i + 1; j++){
            if(i == 0 || j == 0 || j == i)
                answer[i][j] = 1;
            else
                answer[i][j] = answer[i-1][j] + answer[i-1][j-1];
        }
    }
    
    return answer;
    
}


