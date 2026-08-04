/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    int hash[101] = {0}, count = -1;
    for(int i = 0; i < numsSize; i++){
        hash[nums[i]]++;
    }
    int *answer = malloc(sizeof(int) * 100);
    *returnSize = 0;
    for(int i = 1; i <= 100; i++){
        if(count == numsSize - 1)
            break;
        if(hash[i] > 0){
            count++;
        }
        else if(count >= 0){
            answer[(*returnSize)++] = i;
        }
    }

    return answer;
}
