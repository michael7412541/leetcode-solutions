int max(int a, int b){
    return a > b ? a : b;
}
int longestCommonSubsequence(char* text1, char* text2) {
    int size1 = strlen(text1), size2 = strlen(text2);
    int dp[size1+1][size2+1];
    dp[0][0] = 0;
    for(int i = 0; i <= size1; i++){
        for(int j = 0; j <= size2; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else{
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[size1][size2];
}
