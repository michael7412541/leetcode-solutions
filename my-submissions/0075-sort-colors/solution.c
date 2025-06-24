void sortColors(int* nums, int numsSize) {
    int i = 0, j = 0, count = 0, counting[3] = {0};
    int* output = (int*)malloc(sizeof(int)*numsSize);
    for(i = 0; i < numsSize; i++)
    {
        counting[nums[i]]++;
    }
    for(i = 1; i < 3; i++)
    {
        counting[i] += counting[i-1];
    }
    for(i = numsSize - 1; i >= 0; i--)
    {
        output[counting[nums[i]] - 1] = nums[i];
        counting[nums[i]]--;
    }
    for(i = 0; i < numsSize; i++)
    {
        nums[i] = output[i];
    }
    free(output);
}
