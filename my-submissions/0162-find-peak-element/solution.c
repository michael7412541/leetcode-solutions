int findPeakElement(int* nums, int numsSize) {
    int right = numsSize - 1, left = 0, middle = 0;
    while(left < right){
        middle = left + (right - left)/2;
        if(nums[middle] < nums[middle + 1]){
            //上坡 -> peak在右邊
            left = middle + 1;
        }
        else if(nums[middle] > nums[middle + 1]){
            //下坡 -> peak在左邊
            right = middle;
        }
    }
    return left;
}
