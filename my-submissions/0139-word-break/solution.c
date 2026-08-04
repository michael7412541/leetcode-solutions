bool check(char *s, int start, int end, char** wordDict, int wordDictSize){
   
    int size = end - start + 1;
    bool result = false;
    for(int i = 0; i < wordDictSize; i++){
        if(size == strlen(wordDict[i])){
            result = true;
            for(int j = 0; j < size; j++){
                if(s[start + j] != wordDict[i][j]){
                    result = false;
                    break;
                }
            }
            if(result == true)
                return true;
        }
    }
    return false;
}
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    
    int size = strlen(s);
    
    int dp[size+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int i = 1; i <= size; i++){
        for(int j = 0; j < i; j++){
            if(dp[j] == 1){
                if(check(s, j, i-1, wordDict, wordDictSize)){
                    dp[i] = 1;
                    break;
                }
            }
        }
        
    }
    return dp[size];
}
