int pivotIndex(int* nums, int numsSize) {
    if(numsSize < 0)
        return -1;
    if(numsSize == 1)
        return 0;
    
    int left = 0, right = 0, i = 0, sum = 0;
    for(i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    for(i = 0; i < numsSize; i++){
        if(i > 0)
            left += nums[i-1];
        right = sum - left - nums[i];
        if(left == right)
            return i;
    }
    return -1;
}
