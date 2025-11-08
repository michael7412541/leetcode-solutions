int findMin(int* nums, int numsSize) {
    int right = numsSize - 1, left = 0, mid = 0;
    while(left < right){
        mid = left + (right - left)/2;
        if(nums[mid] > nums[right])
            left = mid + 1;
        else if(nums[mid] <= nums[right])
            right--;
        else
            right = mid;
             
    } 
    return nums[left];
}

// 2  0  1 1 1 1 1 1 1 1
// 2  0  1 2 2 2 2 2 2 2
// 2  2  3 3 3 3 3 0 2 2
