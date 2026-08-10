int min(int a, int b, int c){
    if(a <= b && a <= c) return a;
    if(b <= c && b <= a) return b;
    return c;
}
int minDistance(char* word1, char* word2) {
    int size1 = strlen(word1), size2 = strlen(word2);
    int dp[size1+1][size2+1];

    dp[0][0] = 0;
    for(int i = 1; i <= size1; i++) dp[i][0] = i;
    for(int j = 1; j <= size2; j++) dp[0][j] = j;

    for(int i = 1; i <= size1; i++){
        for(int j = 1; j <= size2; j++){
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
            
        }
    }

    return dp[size1][size2];
}
