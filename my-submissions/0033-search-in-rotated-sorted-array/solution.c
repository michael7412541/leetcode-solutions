int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1, mid = 0;
    
    while(left <= right){
         mid  = left + (right - left)/2;
        
        if(target == nums[mid])
            return mid;
        
        if(nums[left] <= nums[mid]){
            if(target < nums[mid] && target > nums[left]){
                right = mid - 1;
            }
            else if(target == nums[left]){
                return left;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(target > nums[mid] && target < nums[right]){
                left = mid + 1;
            }
            else if(target == nums[right])
                return right;
            else{
                right = mid - 1;
            }
        }
    }

    return -1;
}
