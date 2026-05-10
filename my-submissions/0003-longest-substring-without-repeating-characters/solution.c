int cal_hash(int *hash, int size){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(hash[i] > 1)
            return -1;
        else if(hash[i] > 0)
            count++;
    }
    return count;
}
int lengthOfLongestSubstring(char* s) {
    
    int hash[128] = {0};
    int left =0, right = 0, answer = INT_MIN;
    int size = strlen(s);
    if(size == 0)
        return 0;
    for(right = 0; right < size; right++){
        hash[s[right]]++;
        
        while(cal_hash(hash, 128) < 0 && left  <right){//shrink
            hash[s[left]]--;
            left++;
        }
        int temp = cal_hash(hash, 128);
        if(temp > answer)
            answer = temp;
    }
    return answer;
}
