int minSubArrayLen(int target, int* nums, int numsSize) {
    int min = numsSize + 1;
    int left = 0, right = 1;
    int sum = nums[0];
    while(left < numsSize)
    {
        
        if(sum >= target)
        {
            sum -= nums[left];
            if(right - left < min)
                min = right - left;
            left++;
        }
        else if(right < numsSize)
        {
            sum += nums[right];
            
            right++;    
        }
        else
        {
            break;
        }
        //printf("left = %d rightt = %d sum = %d\n", left, right, sum);
    }
    if(min == numsSize + 1)
        return 0;
    else
        return min;
}


