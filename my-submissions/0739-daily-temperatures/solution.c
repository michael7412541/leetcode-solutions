/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int idx, stack[temperaturesSize], top = -1;
    int *answer = malloc(sizeof(int) * temperaturesSize);
    memset(answer, 0, sizeof(int) * temperaturesSize);
    stack[++top] = 0;
    for(int i = 0; i < temperaturesSize; i++){
        idx = stack[top];
        while(top >= 0 && temperatures[i] > temperatures[idx]){
            
            answer[idx] = i - idx;
            top--;
            idx = top >= 0 ? stack[top] : -1;

        }
        stack[++top] = i;
    }
    *returnSize = temperaturesSize;
    return answer;
}
