int minOperations(int* nums, int numsSize, int x) {
    int target = -x;
    for(int i = 0; i < numsSize; i++){
        target += nums[i];
    }
    if(target < 0) return -1;
    if(target == 0) return numsSize;

    int current_sum = 0, min = INT_MAX, left = 0, right = 0;
    for(right = 0; right < numsSize; right++){
        current_sum += nums[right];
        while(left <= right && current_sum > target){
            current_sum -= nums[left++];
        }
        if(current_sum == target){
            if(left + numsSize - 1 - right < min)
                min = left + numsSize - 1 - right;
        }
    }
    if(min == INT_MAX) return -1;
    return min;
}