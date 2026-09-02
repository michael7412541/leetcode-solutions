int max(int a, int b){
    return a > b ? a : b;
}
int maxProfit(int* prices, int pricesSize) {
    int dp[pricesSize][3];
    for(int i = 0; i < pricesSize; i++){
        //dp[i][0] = 今天持有股票
        //dp[i][1] = 今天不持有，而且今天可以買
        //dp[i][2] = 今天 cooldown
        if(i == 0){
            dp[i][0] = -prices[0];
            dp[i][1] = 0;
            dp[i][2] = 0;
        }
        else{
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] -prices[i]);
            dp[i][1] = max(dp[i-1][2], dp[i-1][1]);
            dp[i][2] = dp[i-1][0] + prices[i]; 
        }
    }

    return max(max(dp[pricesSize-1][0], dp[pricesSize-1][1]), dp[pricesSize-1][2]);
}
