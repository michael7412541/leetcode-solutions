int numberOfSubstrings(char* s) {
    int hash[3] = {0}, left = 0, right = 0, answer = 0;
    long size = strlen(s);
    bool condition = false;
    while(left <= right && right < size){

        while(right < size && condition == false){
            hash[s[right] - 'a']++;
            condition = hash[0] > 0 && hash[1] > 0 && hash[2] > 0;
            //printf("l=%d r=%d [0]%d [1]%d [2]%d\n", left, right, hash[0], hash[1], hash[2]);
            right++;
        }
        while(condition == true){
            answer += (size - right + 1);
            hash[s[left] - 'a']--;
            condition = hash[0] > 0 && hash[1] > 0 && hash[2] > 0;
            //printf("l=%d r=%d [0]%d [1]%d [2]%d\n", left, right, hash[0], hash[1], hash[2]);
            left++;
        }
    }
    return answer;
}
