void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int heightChecker(int* heights, int heightsSize) {
    int i = 0, count = 0, j = 0;
    int *sort = (int*)malloc(sizeof(int) * heightsSize);
    memcpy(sort, heights, sizeof(int) * heightsSize);
    for(i = 0; i < heightsSize; i++)
    {
        for(j = i + 1; j < heightsSize; j++)
        {
            if(sort[i] > sort[j])
                swap(&sort[i], &sort[j]);
        }
    }
    for(i = 0; i < heightsSize; i++)
    {
        if(heights[i] != sort[i])
            count++;
    }
    return count;
}
