/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool check(char *s, int left, int right){
    int len = right - left + 1;
    if(len <= 0 || len > 3) return false;
    if(s[left] == '0' && len > 1) return false;
    
    int sum = 0;
    for(int i = left; i <= right; i++){
        sum = sum * 10 + (s[i] - '0');
    }
    return (sum >= 0 && sum <= 255);
}


void dfs(char *path, int pathsize, int index, char **result, char *s, int *returnSize, int size, int segment){
    if(segment == 4){
        if(index == size){
            result[*returnSize] = malloc(sizeof(char) * (pathsize + 1));
            for(int i = 0; i < pathsize; i++){
                result[*returnSize][i] = path[i];
            }
            result[*returnSize][pathsize] = '\0';
            (*returnSize)++;
        }
        return;
    }
    int oldpath = pathsize;
    for(int i = index; i < index + 3 && i < size; i++){
        if(check(s, index, i) == false)
            continue;
        

        for(int j = index; j <= i; j++){
            path[pathsize++] = s[j];
        }
        if(segment < 3){
            path[pathsize++] = '.';
        }
        
        dfs(path, pathsize, i + 1, result, s, returnSize, size, segment + 1);

        pathsize = oldpath;
    }


}
char** restoreIpAddresses(char* s, int* returnSize) {
    int size = strlen(s);
    char **result = malloc(sizeof(char*) * 500);
    char *path = malloc(sizeof(char) * 30);
    *returnSize = 0;
    dfs(path, 0, 0, result, s, returnSize, size, 0);

    return result;
}