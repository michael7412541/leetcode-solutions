/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int binary_search(int *nums, int numsSize, int target){
    int left = 0, right = numsSize, mid = 0;
    while(left < right){
        mid = left + (right - left)/2;
        if(nums[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    
    *returnSize = 2;
    int *answer = malloc(sizeof(int) * 2);
    if(nums == NULL || numsSize == 0){
        answer[0] = -1;
        answer[1] = -1;
        return answer;
    }

    int position = binary_search(nums, numsSize, target);
    printf("%d", position);
    if( position == numsSize || nums[position] != target ){
        answer[0] = -1;
        answer[1] = -1;
    }
    else{
        answer[0] = position;
        answer[1] = binary_search(nums, numsSize, target + 1) - 1;

    }

    return answer;
}
