void sortColors(int* nums, int numsSize) {
    int i = 0, j = 0, count = 0, counting[3] = {0};
    for(i = 0; i < numsSize; i++)
    {
        counting[nums[i]]++;
    }
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < counting[i]; j++)
        {
            nums[count] = i;
            count++;
        }
    }
}
