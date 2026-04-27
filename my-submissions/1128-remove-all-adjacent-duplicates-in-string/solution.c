char* removeDuplicates(char* s) {
    int i = 0, top = -1;
    char *answer = malloc(sizeof(char)*100000);
    while(s[i] != '\0'){
        
        if(top == -1){
            top++;
            answer[top] = s[i];
        }   
        else if(s[i] == answer[top])
            top--;
        else{
            top++;
            answer[top] = s[i];
        }   

        //printf("s[%d] = %c, top = %d\n", i, s[i],top);
        i++;
    }
    //printf("top = %d", top);
    answer[++top] = '\0';

    return answer;

}
