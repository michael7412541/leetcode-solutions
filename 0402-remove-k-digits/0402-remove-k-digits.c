char* removeKdigits(char* num, int k) {
    int lastPos[10];
    for(int i = 0; i < 10; i++) lastPos[i] = -1;
    for(int i = 0; num[i] != '\0'; i++) lastPos[num[i] - '0'] = i;

    char *stack = malloc(sizeof(int) * strlen(num));
    int top = -1, i = 0;
    for(int i = 0; num[i] != '\0'; i++){
        while(top >= 0 && k > 0 && stack[top] > num[i]){
            k--;
            top--;
        }
        
        stack[++top] = num[i];
    }

    top -= k;
    int start = 0;
    while(start <= top && stack[start] == '0'){
        start++;
    }

    if(start > top)
        return "0";


    
    stack[++top] = '\0';

    return stack + start; //很漂亮!!
}
/*
免除額外記憶體複製：stack + start 直接回傳指標，連 strcpy 或另外配 answer 都不用。

邊界清晰：start > top 直接囊括「全部是 0」或「數字全部刪光」的狀況，統一回傳 "0"。*/