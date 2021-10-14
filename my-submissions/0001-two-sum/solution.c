

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int i, j, temp;
    int *result = NULL;
    //int *result = (int*)malloc(sizeof(int)*2);
    //int *result=(int*)malloc(2*sizeof(int)),i,j,temp;
    temp = target;
    for(i = 0 ; i < numsSize ; i++){
        temp = target - nums[i];
        for(j = i + 1 ; j < numsSize ; j++){
            if (temp - nums[j]== 0){
                result = (int*)malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return 0;
}
