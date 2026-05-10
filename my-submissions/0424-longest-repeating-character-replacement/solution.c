int maxhash(int * hash){
    int max = -1;
    for(int i = 0; i < 26; i++){
        if(hash[i] > max)
            max = hash[i];
    }
    return max;
}
int characterReplacement(char* s, int k) {
    int right = 0, left = 0, size = strlen(s), hash[26] = {0}, max_length = INT_MIN;
    for(right = 0; right < size; right++){
        hash[s[right] - 'A']++;
        if(right - left + 1 - maxhash(hash) <= k){
            if(right - left + 1 > max_length)
                max_length = right - left + 1;
        }
        while(right - left + 1 - maxhash(hash) > k && left <= right){
            hash[s[left] - 'A']--;
            left++;
        }


    }
    return max_length;
}
