int search(int* nums, int numsSize, int target) {
    if(nums == NULL || numsSize == 0)
        return -1;
    int left = 0, right = numsSize - 1, mid = 0;
    while(left <= right){
        mid = left + (right - left)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
