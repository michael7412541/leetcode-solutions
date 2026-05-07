int lengthOfLongestSubstring(char* s) {
    if(s[0] == '\0')
        return 0;
    int left = 0, right =0 , max = INT_MIN, count = 0, i = 0, hash[128] = {0};
     for(int i = 0; i < 128; i++)
        hash[i] = -1;

    while(s[right] != '\0'){
        //check hash map
        if(hash[s[right]] >= 0){
            
            left = hash[s[right]] + 1 > left ? hash[s[right]] + 1 : left;
            hash[s[right]] = right;
        }
        else{
            hash[s[right]] = right;
        }
        if(right - left + 1> max)
            max = right - left + 1;
        right++;
    }
    return max;
    
}
