/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    rowIndex++;
    int *answer = (int*)malloc(rowIndex*sizeof(int));
    int i = 0, j =0;
    for(i = 0; i < rowIndex; i++)//第幾層
    {
        for(j = i; j >= 0; j--)//第幾個
        {
            if(i == 0 || i ==1 || j == 0 || i == j)
                answer[j] = 1;
            else
            {
                answer[j] = answer[j - 1] + answer[j];
            }
        }
    }
    *returnSize = rowIndex;
    return answer;
}
/*
1
1 1
1 2 1
1 3 3 1*/
