bool isGood(int* nums, int numsSize) {
    int hash[numsSize + 1];
    memset(hash, 0, sizeof(hash));
    for(int i = 0; i < numsSize; i++){
        if(nums[i] <= 0  || nums[i]  > numsSize)
            return false;
        else
            hash[nums[i]]++;
    }
    for(int i = 1; i < numsSize - 1; i++){
        //printf("hash[%d] = %d\n", i, hash[i]);
        if(hash[i] != 1)
            return false;
    }
    return (hash[numsSize -1 ] == 2);
}
