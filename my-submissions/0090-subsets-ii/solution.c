/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 1024

void dfs(int **result, int *nums, int numsSize, int *returnSize, int **returnColumnSizes, int *path, int pathsize, int index){
    path[pathsize++] = nums[index];

    result[(*returnSize)] = malloc(sizeof(int) * pathsize);
    (*returnColumnSizes)[(*returnSize)] = pathsize;
    for(int i = 0; i < pathsize; i++){
        result[(*returnSize)][i] = path[i];
    }
    (*returnSize)++;
    
    for(int i = index + 1; i < numsSize; i++){
        if(i > index + 1 && nums[i] == nums[i-1])
            continue;
        
        dfs(result, nums, numsSize, returnSize, returnColumnSizes, path, pathsize, i);
    }

}
int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}


int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **result = malloc(sizeof(int*) * MAX_SIZE);
    int *path = malloc(sizeof(int*) * numsSize);
    *returnSize = 1;
    (*returnColumnSizes) = malloc(sizeof(int) * MAX_SIZE);
    (*returnColumnSizes)[0] = 0;
    
    qsort(nums, numsSize, sizeof(int), compare);

    for(int i = 0; i < numsSize; i++){
        if(i == 0){
            dfs(result, nums, numsSize, returnSize, returnColumnSizes, path, 0, i);
        }
        else if(nums[i] != nums[i-1]){
            dfs(result, nums, numsSize, returnSize, returnColumnSizes, path, 0, i);
        }
    }
    free(path);
    return result;    
}
