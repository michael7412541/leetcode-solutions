int longestSubsequence(int* nums, int numsSize) {
    int temp = 0, zero_count = 0;
    for(int i = 0; i < numsSize; i++){
        if(i == 0)
            temp = nums[i];
        else
            temp = temp ^ nums[i];
        if(nums[i] == 0)
            zero_count++;
    }
    if(zero_count == numsSize)
        return 0;
    if(temp == 0)
        return numsSize - 1;
    else
        return numsSize;
}
