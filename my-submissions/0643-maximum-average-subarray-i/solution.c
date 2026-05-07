double findMaxAverage(int* nums, int numsSize, int k) {
    if(k > numsSize || nums == NULL)
        return -1;
    int temp, max, sum = 0;
    double answer = 0;
    for(int i = 0; i < k; i++){
        sum += nums[i];
    }
    max = sum;
    for(int i = k; i < numsSize; i++){
        sum = sum + nums[i] - nums[i - k];
        if(sum > max)
            max = sum;
    }
    answer = (double)max/k;
    return answer;
    
}
