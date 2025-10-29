int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1, middle = 0;
    if(numsSize == 1)
        return nums[0];
    if(nums[right] > nums[left])
        return nums[left];
    while(left < right){
        middle = left + (right - left)/2;
        if(nums[middle] > nums[middle + 1]){
            return nums[middle + 1];
        }
        else if(nums[middle] > nums[right]){
            left = middle + 1;
        }
        else{
            right = middle;
        }
    }
    return -1;
}
