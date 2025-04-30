/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i = digitsSize - 1;
    while(i >= 0)
    {
        if(digits[i] != 9)
            break;
        i--;
    }
    
    if(i < 0)
    {
        int* answer = (int*)malloc((digitsSize+1) * sizeof(int));
        memset(answer, 0, (digitsSize+1) * sizeof(int));
        answer[0] = 1;
        *returnSize = digitsSize+1;
        return answer;
    }
    else
    {
        
        int* answer = (int*)malloc(digitsSize * sizeof(int));
        memset(answer, 0, (digitsSize) * sizeof(int));
        memcpy(answer, digits, digitsSize * sizeof(int));
        answer[i]++;
        for(int j = i + 1; j<digitsSize;j++)
            answer[j] = 0;
        
        *returnSize = digitsSize;
        return answer;
    }
    
    
}
