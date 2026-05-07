int maxSubArray(int* nums, int numsSize) {
    int sum = 0, max = INT_MIN;
    for(int i = 0; i < numsSize; i++){
        if(sum < 0){
            sum = nums[i];
        }
        else{
            sum += nums[i];
        }
        if(sum > max)
            max = sum;
    }
    return max;
}
//關鍵在於轉換題目
///我不是在找所有的subarray 而是在判斷要不要把前面的丟掉 如果前面是負數 那就直接丟掉 因為只會扯後腿 隨便加一個正數都比他大
