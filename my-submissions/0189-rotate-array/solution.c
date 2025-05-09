void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    int i = 0;
    int *answer = (int*)malloc(sizeof(int)*numsSize);
    for(i = 0; i < numsSize; i++)
    {
        answer[i] = nums[(numsSize - k + i) % numsSize];
        //printf(" %d", answer[i]);
    }
    for(i = 0; i < numsSize; i++)
    {
        //answer[i] = nums[(numsSize - k + i) % numsSize];
        //printf(" %d", answer[i]);
        nums[i] = answer[i];
    }
    
}
