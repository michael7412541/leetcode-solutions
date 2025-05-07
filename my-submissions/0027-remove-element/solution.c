int removeElement(int* nums, int numsSize, int val) {
    if(nums == NULL)
        return numsSize;
    int i = 0, k = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != val)
        {
            nums[k] = nums[i];
            k++;    
        }
    }
    return k;
}
