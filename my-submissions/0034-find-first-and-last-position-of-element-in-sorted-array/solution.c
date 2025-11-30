/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *answer = (int*)malloc(sizeof(int)*2);
    if(numsSize < 1){
        *returnSize = 2;
        answer[0] = -1;
        answer[1] = -1;
        return answer;
    }
    int L = 0, R = numsSize - 1, mid = 0;
    int start = 0, end = 0;
    while(L < R){
        mid = L + (R - L)/2;
        if(nums[mid] < target)
            L = mid + 1;
        else
            R = mid;
    }
    if(nums[L] != target){
        start = -1;
    }
    else{
        start = L;
    }
    L = 0;
    R = numsSize - 1;
    while(L < R){
        mid = L + (R - L)/2;
        if(nums[mid] <= target)
            L = mid + 1;
        else
            R = mid;
    }
    
    if (L < numsSize && nums[L] <= target)
        L++;
    end = L - 1;
    if(end < start) end = start;
    if(end >= numsSize) end = numsSize - 1;
    
    
    answer[0] = start;
    if(start == -1)
        answer[1] = -1;
    else
        answer[1] = end;
    
    *returnSize = 2;
    return answer;
    
        
}
