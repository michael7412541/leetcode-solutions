/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    int leftsum = 0, rightsum = 0, i = 0, left[numsSize], right[numsSize];
    int *answer = malloc(sizeof(int)*numsSize);
    for(i = 0; i < numsSize; i++){
        if(i == 0){
            left[i] = 0;
            right[numsSize - i - 1] = 0;
        }
        else{
            leftsum += nums[i-1];
            rightsum += nums[numsSize - i];
            left[i] = leftsum;
            right[numsSize - i - 1] = rightsum;
        }
    }
    for(i = 0; i < numsSize; i++){
        //printf("l = %d, r = %d\n", left[i], right[i]);
        answer[i] = abs(left[i] - right[i]);
    }
    *returnSize = numsSize;
    return answer;
}
