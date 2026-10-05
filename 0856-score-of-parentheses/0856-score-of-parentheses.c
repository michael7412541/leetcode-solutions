int scoreOfParentheses(char* s) {
    int size = strlen(s);
    int sum = 0, top = -1;
    int *stack = malloc(sizeof(int) * size);
    stack[++top] = 0;
    for(int i = 0; i < size; i++){
        if(s[i] == '('){
            stack[++top] = 0;
        }
        else{
            int cur = stack[top--];
            int score = (cur == 0) ? 1 : 2 * cur;
            stack[top] += score;
        }
    }
    int ans = stack[top];
    free(stack);
    return ans;
} 