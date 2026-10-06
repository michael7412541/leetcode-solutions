int minAddToMakeValid(char* s) {
    int size = strlen(s);
    char *stack = malloc(sizeof(char) * size);
    int top = -1;
    for(int i = 0; i < size; i++){
        if(s[i] == ')' && top >= 0 && stack[top] == '(')
            top--;
        else
            stack[++top] = s[i];
    }
    free(stack);
    return top + 1;
}