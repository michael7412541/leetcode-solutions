char* decodeString(char* s) {
    //char *stack = (char*)malloc(sizeof(char)*30);
    char *stack = (char*)malloc(sizeof(char)*9000);
    //int *n_stack = (int*)malloc(sizeof(int)*30);
    int *n_stack = (int*)malloc(sizeof(int)*100);
    int i = 0, n_top = -1, top = -1, count = 0;
    char temp[9000], temp1[9000], answer[9000];
    
    while(s[i] != '\0'){
        if(s[i] >= '0' && s[i] <= '9'){
            int num = 0;
            while(s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + s[i] - '0';
                i++;
            }
            n_stack[++n_top] = num;
        }
        else{
            stack[++top] = s[i];
            if(s[i] == ']'){
                int j = top;
                //while(j >= 0 && s[j] != '['){
                while(j >= 0 && stack[j] != '['){
                    j--;
                }
                count = 0;
                temp[0] = '\0';//???
                for(int d = 0; d < n_stack[n_top]; d++){
                    //for(int k = j + 1; k < i; k++){
                    for(int k = j + 1; k <= top - 1; k++){
                        //temp[count] = s[k]; 
                        temp[count] = stack[k];
                        count++;
                    }
                }
                temp[count] = '\0';//???
                n_top--;
                top = j - 1;
                
                //???
                //把temp接回stack
                for(int t = 0; t < count; t++){
                    stack[++top] = temp[t];
                }
            }
            /*else if(s[i] == '['){
    
            }
            else{
                //temp1[0] = s[i];
                //strcat(temp1, temp);
                temp1[0] = s[i];
                temp1[1] = '\0';
                strcat(temp1, temp);
                answer = temp1;
                top--;
            }*/
            
            i++;   
        }
    }
    
    //?/ 最後從stack中拿出答案
    for(int j = 0; j <= top; j++) {
        answer[j] = stack[j];
    }
    answer[top+1] = '\0';
    free(stack);
    free(n_stack);
    
    return strdup(answer);
}
