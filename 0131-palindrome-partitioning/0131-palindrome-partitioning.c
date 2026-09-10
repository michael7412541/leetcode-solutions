/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 50000
bool check(char *s, int left, int right){
    if(left == right)   return true;
    while(left < right){
        if(s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
void dfs(char *s, char **path, int pathsize, int size, int start, char ***result, int *returnSize, int **returnColumnSizes){
    if(start == size){
        result[*returnSize] = malloc(sizeof(char*) * pathsize);
        (*returnColumnSizes)[*returnSize] = pathsize;
        for(int i = 0; i < pathsize; i++){
            int sub_size = strlen(path[i]);
            result[*returnSize][i] = malloc(sizeof(char) * (sub_size + 1));
            for(int j = 0; j <= sub_size; j++){
                result[*returnSize][i][j] = path[i][j];
            }
            
        }
        (*returnSize)++;
        return;
    }
    for(int i = start; i < size; i++){
        if(check(s, start, i) == false)
            continue;
        int sub_size = i - start + 1;
        char *str = malloc(sizeof(char) * (sub_size + 1));
        for(int j = 0; j < sub_size; j++){
            str[j] = s[j + start];
        }
        str[sub_size] = '\0';
        path[pathsize] = str;
        dfs(s, path, pathsize + 1, size, i+1, result, returnSize, returnColumnSizes);
        free(str);
    }
    /*if(check(s, left, right)){
        result[*returnSize] = malloc(sizeof(char*) * size);
        for(int i = left; i < right; i++){
            result[*returnSize][(*returnColumnSizes)[*returnSize]][i] = s[i];
        }
        (*returnSize)++;
    }
    for(int i = left; i < right; i++){
        if(check(s, left, i)){
            
            result[*returnSize] = malloc(sizeof(char*) * size);
            for(int j = left; j <= i; j++){
                result[*returnSize][(*returnColumnSizes)[*returnSize]][j] = s[j];
            }
            (*returnColumSizes)[*returnSize]++;
            dfs(s, size, i, right, result, returnSize, returnColumnSizes);
            (*returnSize)++;
        }
    }*/
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int size = strlen(s);
    char ***result = malloc(sizeof(char**) * MAX_SIZE);
    char **path = malloc(sizeof(char**) * (size + 1));
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * MAX_SIZE);
    memset(*returnColumnSizes, 0, sizeof(int) * MAX_SIZE);
    dfs(s, path, 0, size, 0, result, returnSize, returnColumnSizes);

    return result;
}