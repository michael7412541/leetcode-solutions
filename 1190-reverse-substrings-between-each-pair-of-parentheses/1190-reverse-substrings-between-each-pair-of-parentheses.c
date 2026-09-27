char* reverseParentheses(char* s) {
    char *stack = malloc(sizeof(char) * 2000),  *temp = malloc(sizeof(char) * 2000);
    int size = strlen(s), top = -1, t = -1;
    for(int i = 0; i < size; i++){
        if(s[i] == ')'){
            while(stack[top] != '('){
                temp[++t] = stack[top--];
            }
            top--;
            for(int j = 0; j <= t; j++){
                stack[++top] = temp[j];
            }

            t = -1;
        }
        else{
            stack[++top] = s[i];
        }
        
    }
    stack[++top] = '\0';
    return stack;
}