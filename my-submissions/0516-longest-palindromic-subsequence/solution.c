int answer = 0;
int max(int a, int b){
    return a > b ? a : b;
}
int longestPalindromeSubseq(char* s) {
    int size = strlen(s);
    int dp[size][size];
    answer = 1;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < size; i++)
            dp[i][i] = 1;//因為單一字元的最長回文子序列就是自己。

    for(int i = size-1; i >= 0; i--){
        for(int j = i+1; j < size; j++){
            if(s[i] == s[j]){
                dp[i][j] = dp[i+1][j-1] + 2;
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
            if(dp[i][j] > answer)
                answer = dp[i][j];
        }
    }
    return answer;
}
