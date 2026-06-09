long long maxTotalValue(int* nums, int numsSize, int k) {
    if(nums == NULL || numsSize == 0)
        return 0;
    long long  max = INT_MIN, min = INT_MAX;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > max)
            max = nums[i];
        if(nums[i] < min)
            min = nums[i];
    }
    return (max - min)*k;
}
