int smallestIndex(int* nums, int numsSize) {
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum = 0;
        while(nums[i] != 0){
            sum += nums[i] % 10;
            nums[i] = nums[i] / 10;
        }
        if(sum == i)
            return i;
    }
    return -1;
}