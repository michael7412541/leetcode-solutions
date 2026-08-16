int combinationSum4(int* nums, int numsSize, int target) {
    long long dp[target+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i <= target ; i++){
        for(int j = 0; j < numsSize; j++){
            
            dp[i] += (i >= nums[j] ? dp[i - nums[j]] : 0);
            if(dp[i] > INT_MAX) dp[i] =  0;
        }
    }

    return (int)dp[target];
}
