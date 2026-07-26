bool canJump(int* nums, int numsSize) {
    int far = 0;

    for(int i = 0; i < numsSize; i++){
        if(far < i)
            return false;
        far = far > nums[i] + i ? far : nums[i] + i;
    }
    return true;

}
