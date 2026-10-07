int totalNumbers(int* digits, int digitsSize) {
    int count[10] = {0}, answer = 0, test[10] = {0}, flag = 0;
    for(int i = 0; i < digitsSize; i++)
        count[digits[i]]++;
    for(int i = 100; i < 999; i+=2){
        for(int j = 0; j <= 9; j++){
            test[j] = 0;
        }
        int a = i / 100;
        int b = i / 10 % 10;
        int c = i % 10;
        test[a]++;
        test[b]++;
        test[c]++;
        flag = 1;
        for(int j = 0; j <= 9; j++){
            if(test[j] > count[j]){
                flag = 0;
                break;
            }
        }
        if(flag == 1) answer++;
        
    }
    return answer;
}