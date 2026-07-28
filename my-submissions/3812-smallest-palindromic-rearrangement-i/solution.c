char* smallestPalindrome(char* s) {
    int size = strlen(s);
    int hash[26] = {0}, count = 0, mid = 0;
    for(int i = 0; i < size; i++){
        hash[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(hash[i] == 1)
            mid = i;
        for(int j = 0; j < hash[i]/2; j++){
            
            s[count] = (char)(i + 'a');
            s[size - count - 1] = (char)(i + 'a');

            //printf("s[%d] = %c, s[%d] = %c\n", count, (char)(i + 'a'), size - count - 1, (char)(i + 'a'));
            count++;
        }
    }
    if(mid != 0){
        s[size/2] = (char)(mid + 'a');
    }
    return s;
}
