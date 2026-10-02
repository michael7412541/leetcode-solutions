/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrace(int n, int open, int close, int pathsize, char *path, char **answer, int *returnSize){
    if(close > open)
        return;
    if(pathsize == n * 2){
        answer[(*returnSize)] = malloc(sizeof(char) * (pathsize + 1));
        for(int i = 0; i < pathsize; i++){
            answer[*returnSize][i] = path[i];
        }
        answer[*returnSize][pathsize] = '\0';
        (*returnSize)++;
        return;
    }
    if(open < n){
        path[pathsize] = '(';
        backtrace(n, open + 1, close, pathsize + 1, path, answer, returnSize);
    }
    if(close < open){
        path[pathsize] = ')';
        backtrace(n, open , close + 1, pathsize + 1, path, answer, returnSize);
    }

}

char** generateParenthesis(int n, int* returnSize) {
    char *path = malloc(sizeof(char)*(n*2 + 1));
    char **answer = malloc(sizeof(char*) * 2000);
    *returnSize = 0;
    backtrace(n, 0, 0, 0, path, answer, returnSize);
    return answer;    
}