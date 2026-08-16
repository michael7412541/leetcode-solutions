int change(int amount, int* coins, int coinsSize) {
    //state definition: dp[i][j]為前i個數字可以拼出j的combination有幾種
    long long dp[coinsSize+1][amount+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= coinsSize; i++){
        for(int j = 0; j <= amount; j++){
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            else if(i == 0){
                dp[i][j] = 0;
            }
            else if(j == 0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = (dp[i-1][j] + (j-coins[i-1] >= 0 ? dp[i][j-coins[i-1]] : 0) > INT_MAX) ? 0 : dp[i-1][j] + (j-coins[i-1] >= 0 ? dp[i][j-coins[i-1]] : 0);
            }
        }
    }
    return dp[coinsSize][amount];
}
