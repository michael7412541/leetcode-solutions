int dominantIndex(int* nums, int numsSize) {
    int max1 = 0, max2 = 0;
    int i = 0,index = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] > max1)
        {
            max2 = max1;
            max1 = nums[i];
            index = i;
        }
        else if(nums[i] > max2)
        {
            max2 = nums[i];
        }
    }
    if(max1 >= 2*max2)
        return index;
    else
        return -1;
}
