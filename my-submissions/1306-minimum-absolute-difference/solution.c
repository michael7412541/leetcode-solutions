/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    long long i = 0, j = 0, count = 0, min_diff = 0;
    
    *returnColumnSizes = (int*)malloc(arrSize * sizeof(int));
    //qsort(arr, arrSize, sizeof(int), compare);
    int *output = (int*)malloc(sizeof(int)*arrSize);
    //int *counting = (int*)malloc(sizeof(int)*2000001);
    long long counting[2000001] = {0};//很重要!!! 一定要先設成0

    for(i = 0; i < arrSize; i++)
    {
        arr[i] += 1000000; // 0 <= new arr <= 10^6+10^6 = 2000000
        counting[arr[i]]++; 
    }
    for(i = 1; i < 2000001; i++)
    {
        counting[i] += counting[i-1];
    }
    for(i = arrSize - 1; i >= 0; i--)
    {
        output[counting[arr[i]] - 1] = arr[i];
        counting[arr[i]]--;
    }
    for(i = 0; i < arrSize; i++)
    {
        arr[i] = output[i] - 1000000;
    }
    
    free(output);
    //free(counting);
    
    
    min_diff = arr[1] - arr[0];
    for(i = 0; i < arrSize - 1; i++)
    {
        if((arr[i+1] - arr[i]) < min_diff)
            min_diff = arr[i+1] - arr[i];
    }
    
    for(i = 0; i < arrSize - 1; i++)
    {
        if((arr[i] + min_diff) == arr[i+1])
            count++;
    }
    
    int **answer = (int**)malloc(count*sizeof(int*));
    
    for(i = 0, count = 0; i < arrSize - 1; i++)
    {
        if((arr[i] + min_diff) == arr[i+1])
        {
            answer[count] = (int*)malloc(2*sizeof(int));
            (*returnColumnSizes)[count] = 2;
            answer[count][0] = arr[i];
            answer[count][1] = arr[i+1];
            count++;
        }    
    }
    
    
    *returnSize = count;
    return answer;
}
