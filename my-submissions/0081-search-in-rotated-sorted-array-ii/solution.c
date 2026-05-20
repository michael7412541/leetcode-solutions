bool search(int* nums, int numsSize, int target) {
    int mid = 0, left = 0, right = numsSize - 1, k = 0;
    while(left <= right){
        mid = left + (right - left)/2;
        if(nums[mid] == target)
            return true;
        if(nums[mid] == nums[left] && nums[mid] == nums[right]){
           left++;
           right--;
        }
        else if(nums[mid] >= nums[left]){
           if(target >= nums[left] && target < nums[mid]){
            right = mid - 1;
           }
           else{
            left = mid + 1;
           }
        }   
        else{
            if(target > nums[mid] && target <= nums[right]){
            left = mid + 1;
           }
           else{
            right = mid - 1;
           }
        }
    }
    

    return false;

}
