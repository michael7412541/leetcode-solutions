/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

void dfs(int *nums, int size, int target, int *returnSize, int **returnColumnSizes, int sum, int *path, int pathsize, int **result, int index){
    
    if(sum == target){
        result[(*returnSize)] = malloc(sizeof(int) * pathsize);
        (*returnColumnSizes)[(*returnSize)] = pathsize;
        for(int i = 0; i < pathsize; i++){
            result[(*returnSize)][i] = path[i];
        }
        (*returnSize)++;
        return;
    }
    
    for(int i = index; i < size; i++){
        if(sum + nums[i] > target) return;

        path[pathsize++] = nums[i];

        dfs(nums, size, target, returnSize, returnColumnSizes, sum +nums[i], path, pathsize, result, i);
        

        pathsize--;
    }
    
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int **result = malloc(sizeof(int*) * 1000);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 1000);
    int *path = malloc(sizeof(int) * 1000);
    qsort(candidates, candidatesSize, sizeof(int), compare);
    dfs(candidates, candidatesSize, target, returnSize, returnColumnSizes, 0, path, 0, result, 0);
    free(path);
    return result;
}
