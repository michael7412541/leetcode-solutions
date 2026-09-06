/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int index, int hash[], int *path, int pathsize, int *nums, int numsSize, int **result, int *returnSize, int **returnColumnSizes){
    path[pathsize++] = nums[index];
    hash[nums[index] + 10]++;

    if(pathsize == numsSize){
        result[*returnSize] = malloc(sizeof(int) * pathsize);
        for(int i = 0; i < pathsize; i++){
            result[*returnSize][i] = path[i];
        }
        (*returnColumnSizes)[(*returnSize)] = pathsize; 
        (*returnSize)++;

        // 回溯：退出前還原當前節點狀態 這AI提示的
        hash[nums[index] + 10]--;


        return;
    }
    
    
    for(int i = 0; i < numsSize; i++){
        if(hash[nums[i] + 10] == 0){
            dfs(i, hash, path, pathsize, nums, numsSize, result, returnSize, returnColumnSizes);
        }
    }

    // 回溯：當前分支所有子節點探訪完畢，撤銷當前選擇 這AI提示的
    hash[nums[index] + 10]--;
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int hash[21] = {0};
    int **result = malloc(sizeof(int*) * 720);
    int *path = malloc(sizeof(int) * numsSize);
    *returnColumnSizes = malloc(sizeof(int*) * 720);
    *returnSize = 0;
    for(int i = 0; i < numsSize; i++)
        dfs(i, hash, path, 0, nums, numsSize, result, returnSize, returnColumnSizes);
    
    return result;

}
