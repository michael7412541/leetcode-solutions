int numDecodings(char* s) {

    int size = strlen(s);
    int dp[size];
    dp[0] = s[0] != '0' ? 1 : 0;
    
    for(int i = 1; i < size; i++){
        if(s[i] == '0'){
            if(s[i-1] == '1' || s[i-1] == '2')
                dp[i] = (i >= 2 ? dp[i-2] : 1);
            else
                dp[i] = 0; 
        }
        else if(s[i] >= '1' && s[i] <= '6'){
            dp[i] = dp[i-1];
            if(s[i-1] == '1' || s[i-1] == '2')
                dp[i] += (i >= 2 ? dp[i-2] : 1);
        }
        else{
            dp[i] = dp[i-1];
            if(s[i-1] == '1')
                dp[i] += (i >= 2 ? dp[i-2] : 1);
        }
        
    }

    return dp[size-1];
}
