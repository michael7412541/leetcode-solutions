/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int index, int pathsize, int *nums, int numsSize, int **result, int *path, int *returnSize, int **returnColumnSizes){
    path[pathsize++] = nums[index];
    
    result[*returnSize] = malloc(sizeof(int) * pathsize);
    for(int i = 0; i < pathsize; i++){
        result[*returnSize][i] = path[i];
    }
    (*returnColumnSizes)[(*returnSize)] = pathsize; 
    (*returnSize)++;
    
    for(int i = index + 1; i < numsSize; i++){
        dfs(i, pathsize, nums, numsSize, result, path, returnSize, returnColumnSizes);
    }
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **result = malloc(sizeof(int*) * 1024);
    int *path = malloc(sizeof(int) * 10);
    *returnSize = 0;
    result[(*returnSize)++] = NULL;
    *returnColumnSizes = malloc(sizeof(int) * 1024);
    *returnColumnSizes[0] = 0;
    for(int i = 0; i < numsSize; i++){
        dfs(i, 0, nums, numsSize, result, path, returnSize, returnColumnSizes);
    }

    return result;
}
