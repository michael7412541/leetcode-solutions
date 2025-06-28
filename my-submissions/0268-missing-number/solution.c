int missingNumber(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)
        return 0;
    int i = 0, result1 = 0, result0 = 0;
    
    for(i = 0; i < numsSize; i++)
    {
        result0 = result0 ^ i;
        result1 = result1 ^ nums[i];
    }
    result0 = result0 ^ numsSize;
    return result1 ^ result0;
}
