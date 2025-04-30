int pivotIndex(int* nums, int numsSize) {
    //int left = 0, right = numsSize-1;
    int left_sum = 0, sum = 0;
    int i;
    for(i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }
    printf("%d", sum);
    for(i = 0; i < numsSize; i++)
    {
        
        if((sum - nums[i]- left_sum) == left_sum)
            break;
        left_sum += nums[i];
    }
    if(i < numsSize)
        return i;
    else        
        return -1;
}
