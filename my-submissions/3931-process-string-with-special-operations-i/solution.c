void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
char* processStr(char* s) {
    if(s == NULL)
        return NULL;
    int size = strlen(s);
    char *answer = malloc(sizeof(char) * 1000000);
    int pos =-1;

    for(int i = 0; i < size; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            answer[++pos] = s[i];
        }
        else if(s[i] == '*'){
            if(pos > -1)
                pos--;
        }
        else if(s[i] == '#'){
            for(int j = 0; j <= pos; j++){
                //printf("pos = %d\n", pos);
                answer[pos + j + 1] = answer[j];
            }
            pos = pos * 2 + 1;
            
        }
        else if(s[i] == '%'){
            if(pos >= 0)
            for(int j = 0; j <= pos/2; j++){
                swap(&answer[j], &answer[pos - j]);
            }
        }
        else
            return NULL;
    }
    answer[++pos] = '\0';
    return answer;
}
