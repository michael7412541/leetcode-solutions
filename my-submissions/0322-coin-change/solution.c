int min(int a, int b){
    return a > b ? b : a;
}
int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount+1];
    dp[0] = 0;
    for(int i = 1; i <= amount; i++){
        dp[i] = 30000;
    }

    for(int i = 1; i <= amount; i++){
        int temp = 0;
        for(int j = 0; j < coinsSize; j++){
            if(i >= coins[j]){
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }

    }
    return dp[amount] == 30000 ? -1 : dp[amount];
}
