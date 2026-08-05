int lengthOfLIS(int* nums, int numsSize) {
    int temp = 0, answer = 0, dp[numsSize];
    //memset(dp, 1, sizeof(int) * numsSize);

    for(int i = 0; i < numsSize; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                temp = dp[j] + 1;
                if(temp > dp[i])
                    dp[i] = temp;
            }
        }
    }
    for(int i = 0; i < numsSize; i++){
        //printf("%d ", dp[i]);
        if(dp[i] > answer)
            answer = dp[i];
    }
    return answer;
}
