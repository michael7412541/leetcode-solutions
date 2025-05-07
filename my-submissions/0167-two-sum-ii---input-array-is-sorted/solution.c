/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    if(numbers == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int* answer = (int*)malloc(2*sizeof(int));
    int top = 0, bottom = numbersSize - 1;
    
    while(top < bottom)
    {
        if(numbers[top] + numbers[bottom] > target)
        {
            bottom--;
        }
        else if(numbers[top] + numbers[bottom] < target)
        {
            top++;
        }
        else
        {
            answer[0] = top + 1;
            answer[1] = bottom + 1;
            *returnSize = 2;
            return answer;
        }
    }
    
    *returnSize = 0;
    return NULL;
    
}
