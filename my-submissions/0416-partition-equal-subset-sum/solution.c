bool canPartition(int* nums, int numsSize) {
    int target = 0;
    for(int i = 0; i < numsSize; i++){
        target += nums[i];
    }
    if(target % 2 == 1) return false;
    target = target / 2;

    bool dp[numsSize + 1][target + 1];
    dp[0][0] = true;//dp[i][j] 表示前i個item 是否能組成 j
    for(int i = 0; i <= numsSize; i++){
        for(int j = 0; j <= target; j++){
            if(i == 0 && j == 0)
                dp[i][j] = true;
            else if(i == 0 || j == 0) 
                dp[i][j] = false;
            else
                dp[i][j] = dp[i-1][j] || (j - nums[i-1] >= 0 ? dp[i-1][j-nums[i-1]] : false);
        }
    }
    return dp[numsSize][target];
}
