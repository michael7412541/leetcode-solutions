/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int *answer = malloc(sizeof(int) * numsSize);
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] < pivot){
            answer[count++] = nums[i];
        }
    }
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == pivot){
            answer[count++] = nums[i];
        }
    }
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > pivot){
            answer[count++] = nums[i];
        }
    }
    *returnSize = numsSize;
    return answer;
}
