int missingNumber(int* nums, int numsSize) {
    int hash[numsSize + 1];
    memset(hash, 0, sizeof(hash));
    for(int i = 0; i < numsSize; i++){
        hash[nums[i]]++;
    }
    for(int i = 0; i < numsSize + 1; i++){
        if(hash[i] == 0)
            return i;
    }
    return -1;
}
