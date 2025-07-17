bool isValid(char* s) {
    int i = 0,top = -1, len = strlen(s);
    char *stack = (char*)malloc(sizeof(char)*len);
    for(i = 0; i < len; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
            top++;
            stack[top] = s[i];
        }
        else{
            if(top == -1)
                return false;
            if((s[i] == ']' && stack[top] == '[') ||
               (s[i] == ')' && stack[top] == '(') ||
               (s[i] == '}' && stack[top] == '{')){
                top--;
            }
            else{
                return false;
            }
        }
    }
    if(top == -1)
        return true;
    else
        return false;
}
