int max(int a, int b){
    return a > b ? a : b;
}
int house_robber(int *nums, int start, int end){
    int a, b, c  = -1;
    a = nums[start];
    b = max(nums[start], nums[start+1]);
    for(int i = start + 2; i <= end; i++){
        a = a + nums[i];
        c = max(a, b);
        a = b;
        b = c;
    }
    return c > 0 ? c : max(a,b);
}
int rob(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    if(numsSize == 2)
        return max(nums[0], nums[1]);
    return max(house_robber(nums, 0, numsSize - 2), house_robber(nums, 1, numsSize - 1));
}
