/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

void dfs(int *path, int pathsize, int *nums, int size, int index, int *returnSize, int **returnColumnSizes, int **result, int sum, int target){
    if(sum == target){
        //printf("pathsize = %d, index = %d\n", pathsize, index);

        result[*returnSize] = malloc(sizeof(int) * pathsize);
        (*returnColumnSizes)[*returnSize] = pathsize;
        for(int i = 0; i < pathsize; i++){
            result[*returnSize][i] = path[i];
        }
        (*returnSize)++;
        return;
    }
    for(int i = index; i < size; i++){
        if(sum + nums[index] > target)
            return;
        if(i > index && nums[i] == nums[i-1])
            continue;
        path[pathsize] = nums[i];
        dfs(path, pathsize + 1, nums, size, i + 1, returnSize, returnColumnSizes, result, sum + nums[i], target);
    }
        
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), compare);
    *returnSize = 0;
    (*returnColumnSizes) = malloc(sizeof(int) * 1000);
    int **result = malloc(sizeof(int*) * 1000);
    int *path = malloc(sizeof(int) * candidatesSize);
    dfs(path, 0, candidates, candidatesSize, 0, returnSize, returnColumnSizes, result, 0, target);

    return result;
}
