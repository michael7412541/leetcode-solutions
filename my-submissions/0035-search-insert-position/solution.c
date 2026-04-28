
int binary_search(int *nums, int left, int right, int val){
    int mid = left + (right - left)/2;
    if(val == nums[mid] || left == right)
        return mid;
    else if(val > nums[mid])
        return binary_search(nums, mid + 1, right, val);
    else
        return binary_search(nums, left, mid, val);
}
int searchInsert(int* nums, int numsSize, int target) {
    if(target > nums[numsSize - 1])
        return numsSize;
    else if(target < nums[0])
        return 0;
    else
        return binary_search(nums, 0, numsSize - 1, target);
}

