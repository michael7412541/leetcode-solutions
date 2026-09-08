/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 1024

void dfs(int **result, int *nums, int numsSize, int *returnSize, int **returnColumnSizes, int *path, int pathsize, int index){
    
    result[(*returnSize)] = malloc(sizeof(int) * pathsize);
    (*returnColumnSizes)[(*returnSize)] = pathsize;
    for(int i = 0; i < pathsize; i++){
        result[(*returnSize)][i] = path[i];
    }
    (*returnSize)++;

    
    for(int i = index; i < numsSize; i++){
        if(i > index && nums[i] == nums[i-1])
            continue;
        path[pathsize++] = nums[i];
        dfs(result, nums, numsSize, returnSize, returnColumnSizes, path, pathsize, i+1);
        pathsize--;
    }
    
}
int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}


int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **result = malloc(sizeof(int*) * MAX_SIZE);
    int *path = malloc(sizeof(int*) * numsSize);
    *returnSize = 0;
    (*returnColumnSizes) = malloc(sizeof(int) * MAX_SIZE);
    
    qsort(nums, numsSize, sizeof(int), compare);


    dfs(result, nums, numsSize, returnSize, returnColumnSizes, path, 0, 0);

    free(path);
    return result;    
}
