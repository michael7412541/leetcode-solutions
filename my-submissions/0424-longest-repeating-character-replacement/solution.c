int max_hash(int *hash){
    int max = INT_MIN;
    for(int i = 0; i < 26; i++){
        if(hash[i] > max)
            max = hash[i];
    }
    return max;
}
int characterReplacement(char* s, int k) {
    int hash[26] = {0}, right = 0, left = 0, answer = 0;
    int size = strlen(s);
    for(right = 0; right < size; right++){
        hash[s[right] - 'A']++;
        while(max_hash(hash) + k < (right - left + 1) && left <= right){
            hash[s[left] - 'A']--;
            left++;
           
        }
        if(right - left + 1 > answer)
                answer = right - left + 1;
    }
    return answer;
}
