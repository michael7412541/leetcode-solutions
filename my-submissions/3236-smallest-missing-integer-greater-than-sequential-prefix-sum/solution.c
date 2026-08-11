int missingInteger(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0]+1;
    int i = 0;
    for(i = 1; i < numsSize; i++){
        if(nums[i] - nums[i-1] != 1)
            break;
    }
    int sum = 0, k;
    for(int j = 0; j < i; j++){
        sum += nums[j];
    }
    printf("%d", sum);
    while(1){
        for(k = i-1; k < numsSize; k++){
            if(sum == nums[k])
                break;
        }
        if(k == numsSize)
            return sum;
        else
            sum++;
    }

    return sum;
}
