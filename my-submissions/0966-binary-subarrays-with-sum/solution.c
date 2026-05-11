int atMost(int *nums, int numsSize, int goal){
    int hash[2] = {0}, right = 0, left = 0, count = 0;
    for(right = 0; right < numsSize; right++){
        hash[nums[right]]++;
        while(hash[1] > goal && left <= right){
            hash[nums[left]]--;
            left++;
        }
        count += right - left + 1;
    }
    return count;
}
int numSubarraysWithSum(int* nums, int numsSize, int goal) {
    
    return atMost(nums, numsSize, goal) - atMost(nums, numsSize, goal - 1);
}
