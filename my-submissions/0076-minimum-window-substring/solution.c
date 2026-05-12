bool isInclude(int *hash1, int *hash2){
    for(int i = 0; i < 128; i++){
        if(hash2[i] != 0){
            if(hash2[i] > hash1[i])
                return false;
        }
    }
    return true;
}
char* minWindow(char* s, char* t) {
    int size1 = strlen(s), size2 = strlen(t);
    int hash1[128] = {0}, hash2[128] = {0};
    int right = 0, left = 0, answer = size1 + 1, L = -1, R = -1;
    for(int i = 0; i < size2; i++){
        hash2[t[i]]++;
    }
    for(right = 0; right < size1; right++){
        hash1[s[right]]++;
        while(isInclude(hash1, hash2)){
            if(right - left + 1 < answer){
                answer = right - left + 1;
                L = left;
                R = right;
            }
            hash1[s[left]]--;
            left++;
        }
        
    }
    char *result = malloc(sizeof(char)*(answer+1));
    strncpy(result, s + L, answer);
    result[answer] = '\0';
    if(L == -1)
        return "";
    else
        return result;
}
