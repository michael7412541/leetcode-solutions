int minimumPushes(char* word) {
    int size = strlen(word);
    int answer = 0;
    if(size <= 8){
        answer = size;
    }
    else if(size <= 16){
        answer = 8 + (size - 8)*2;
    }
    else if(size <= 24){
        answer = 8 + 16 + (size - 16)*3;
    }
    else{
        answer = 8 + 16 + 24 + (size - 24)*4;
    }
    return answer;
}
