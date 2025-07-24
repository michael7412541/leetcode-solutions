int evalRPN(char** tokens, int tokensSize) {
    int num = 0, len = 0, i = 0, j = 0, top = -1, temp = 0, sign = 0;
    int* stack = (int*)malloc(sizeof(int)*tokensSize);
    for(i = 0; i < tokensSize; i++){
        len = strlen(tokens[i]);
        num = 0;
        //deal with sign bit
        if(len >= 2 && tokens[i][0] == '-')
            sign = 1;
        else
            sign = 0;
        j = sign;
        
        //change to int
        while(tokens[i][j] != '\0'){
            //printf("tokens[%d][%d] = %d\n",i,j, num);
            num *= 10;
            num += tokens[i][j] - '0';
            
            j++;
        }
        if(sign == 1)
            num = -num;
        //printf("num = %d\n", num);
        
        if(tokens[i][0] == '+'){
            temp = stack[top] + stack[top - 1];
            stack[--top] = temp;
        }
        else if(tokens[i][0] == '-' && len == 1){
            temp = stack[top-1] - stack[top];
            stack[--top] = temp;
        }
        else if(tokens[i][0] == '*'){
            temp = stack[top-1] * stack[top];
            stack[--top] = temp;
        }
        else if(tokens[i][0] == '/'){
            temp = stack[top-1] / stack[top];
            stack[--top] = temp;
        }
        else{
            stack[++top] = num; 
        }
         
    }
    return stack[0];
}
