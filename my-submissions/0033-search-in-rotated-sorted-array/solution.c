int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1, mid = 0;
    
    while(left <= right){
         mid  = left + (right - left)/2;
        //printf("L:num[%d] = %d, R:num[%d] = %d, M:num[%d] = %d\n", left,nums[left],right,nums[right],mid,nums[mid]);
       
        if(target == nums[mid])
            return mid;
        
        if(nums[left] <= nums[mid]){
            if(nums[left] <= target && target < nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(nums[mid] < target && target <= nums[right]){
                left = mid + 1;
            }
            else{
               right = mid - 1; 
            }
        }
    }
    return -1;
}
