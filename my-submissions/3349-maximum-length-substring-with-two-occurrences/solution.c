int maximumLengthSubstring(char* s) {
    int size = strlen(s);
    int hash[26] = {0};
    int answer = 0, left = 0, right = 0;
    for(right = 0; right < size; right++){
        hash[s[right] - 'a']++;
        while(hash[s[right] - 'a'] > 2){
            hash[s[left++] - 'a']--;
        }
        if(right - left + 1 > answer)
            answer = right - left + 1;
    }
    return answer;
}
