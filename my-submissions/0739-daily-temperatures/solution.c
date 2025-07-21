/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *answer = (int*)calloc(temperaturesSize, sizeof(int));
    int *stack = (int*)malloc(temperaturesSize*sizeof(int));
    *returnSize = temperaturesSize;
    int i = 0, count = 0;
    int top = -1;
    for(i = 0; i < temperaturesSize; i++){
                
        while(top >= 0 && temperatures[i] > temperatures[stack[top]]){
            int prev = stack[top];
            //pop
            top--;
            answer[prev] = i - prev;
                
        }
        //push
        top++;
        stack[top] = i;
    }
    return answer;
}
