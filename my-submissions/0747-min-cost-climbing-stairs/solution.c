int min(int a, int b){
    return a < b ? a : b;
}
int minCostClimbingStairs(int* cost, int costSize) {
    int dp[costSize+1], a, b, c;
    //dp[0] = 0;
    a = 0;
    //dp[1] = 0;
    b = 0;
    for(int i = 2; i <= costSize; i++){
        //dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);

        c = min(a + cost[i-2], b + cost[i-1]);
        a = b;
        b = c;

    }
    return c;//dp[costSize];
}
