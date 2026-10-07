int totalNumbers(int* digits, int digitsSize) {
    int count[10] = {0}, answer = 0, flag = 0;
    for(int i = 0; i < digitsSize; i++)
        count[digits[i]]++;
    for(int i = 100; i < 999; i+=2){
  
        int a = i / 100;
        int b = i / 10 % 10;
        int c = i % 10;

        count[a]--;
        count[b]--;
        count[c]--;
        if(count[a] >= 0 && count[b] >= 0 && count[c] >= 0)
            answer++;
        
        count[a]++;
        count[b]++;
        count[c]++;
        
    }
    return answer;
}