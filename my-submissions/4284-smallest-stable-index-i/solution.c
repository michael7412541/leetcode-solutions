int firstStableIndex(int* nums, int numsSize, int k) {
    if(numsSize == 1)
        return 0;
    int largest[numsSize], smallest[numsSize];
    memset(largest, 0, sizeof(largest));
    memset(smallest, 0, sizeof(smallest));
    largest[0] = nums[0];
    smallest[numsSize-1] = nums[numsSize-1];
    for(int i = 1; i < numsSize; i++){
        if(nums[i] > largest[i-1])
            largest[i] = nums[i];
        else
            largest[i] = largest[i-1];
    }
    for(int i = numsSize - 2; i >= 0; i--){
        if(nums[i] < smallest[i+1])
            smallest[i] = nums[i];
        else
            smallest[i] = smallest[i+1];
    }
    for(int i = 0; i < numsSize; i++){
        if(largest[i] - smallest[i] <= k)
            return i;
    }
    return -1;

}
