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
    int i = 0, j = 0, count = 0, min_diff = 0;
    
    *returnColumnSizes = (int*)malloc(arrSize * sizeof(int));
    qsort(arr, arrSize, sizeof(int), compare);
   /* for(i = 0; i < arrSize; i++)
    {
        //*answer = (int*)malloc(2*sizeof(int));
        //answer[i] = (int*)malloc(2*sizeof(int));
        //*returnColumnSizes[i] = 2;
        //(*returnColumnSizes)[i] = 2;
        for(j = i + 1; j < arrSize; j++)
        {
            if(arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }*/
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
