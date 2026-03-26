char* addBinary(char* a, char* b) {
    int len_a = strlen(a), len_b = strlen(b);
    int len = (len_a > len_b) ? len_a + 1 : len_b + 1;
    int i = len_a - 1, j = len_b - 1, carry = 0;
    char *answer = malloc(sizeof(char) * (len + 1));
    answer[len] = '\0';
    int k = len - 1;
    while(i >= 0 || j >= 0 || carry > 0){
        
        int temp = carry + (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
        if(temp == 3){
            carry = 1;
            answer[k--] = '1';
        }
        else if(temp == 2){
            carry = 1;
            answer[k--] = '0';
        }
        else{
            carry = 0;
            answer[k--] = temp + '0';
        }
        i--;
        j--;
    }
    
   if (k >= 0) {
        int offset = k + 1; // 這是真正字串開始的位置
        for (int m = 0; m <= (len - offset); m++) {
            answer[m] = answer[m + offset];
        }
    }
    return answer;
}
