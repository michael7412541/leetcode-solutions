/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int **result, int *nums, int numsSize, int *returnSize, int **returnColumnSizes, int *path, int pathsize, int *visited, int index){
    path[pathsize++] = nums[index];
    visited[index] = 1;

    if(pathsize == numsSize){
        result[*returnSize] = malloc(sizeof(int) * numsSize);
        (*returnColumnSizes)[*returnSize] = numsSize;
        for(int i = 0; i < numsSize; i++){
            result[*returnSize][i] = path[i];
        }
        (*returnSize)++;
        visited[index] = 0;
        return;
    }


    for(int i = 0; i < numsSize; i++){
        if(visited[i] == 0){
            /*if(i == 0){
                dfs(result, nums, numsSize, returnSize, returnColumnSizes, path, pathsize, visited, i);
            }
            else if(nums[i] != nums[i-1]){
                dfs(result, nums, numsSize, returnSize, returnColumnSizes, path, pathsize, visited, i);
            }*/
            // 同層去重：前一個相同數字若沒被使用（剛被回溯撤銷），就跳過
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) {
                continue;
            }
            // 關鍵：這裡要傳入遞增後的 pathsize，不能傳 0
            dfs(result, nums, numsSize, returnSize, returnColumnSizes, path, pathsize, visited, i);



        }
    }
    visited[index] = 0;
}

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    int **result = malloc(sizeof(int*) * 1000);
    int *path = malloc(sizeof(int) * numsSize);
    int *visited = malloc(sizeof(int) * numsSize);
    memset(visited, 0, sizeof(int) * numsSize);
    *returnColumnSizes = malloc(sizeof(int) * 1000);
    *returnSize = 0;

    for(int i = 0; i < numsSize; i++){
        if(visited[i] == 0){
            if(i == 0){
                dfs(result, nums, numsSize, returnSize, returnColumnSizes, path, 0, visited, i);
            }
            else if(nums[i] != nums[i-1]){
                dfs(result, nums, numsSize, returnSize, returnColumnSizes, path, 0, visited, i);
            }
        }
    }

    return result;
}
