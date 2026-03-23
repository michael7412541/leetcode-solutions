int dominantIndex(int* nums, int numsSize) {
    if(numsSize < 0)
        return -1;
    int max1 = -1, max2 = -1, index = 0;
    for(int i = 0; i < numsSize; i++){
        if(max1 < nums[i]){
            max2 = max1;
            max1 = nums[i];
            index = i;
        }
        else if(max2 < nums[i]){
            max2 = nums[i];
        }
    }
    if(max1 >= max2 * 2)
        return index;
    else
        return -1;
}
