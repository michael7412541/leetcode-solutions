int compare(void const *a, void const *b){
    return (*(int*)a - *(int*)b);
}
int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    int sum = 0, min = 101;
    for(int i = 0; i < numsSize; i++){
         
        
        if(nums[i] < 0){
            if(k > 0){
                nums[i] = -nums[i];
                k--;
            }
        }
        if(nums[i] <  min ){
             min = nums[i];
            
        }
        sum += nums[i];
     
           
    }
    //printf("sum = %d, min = %d", sum, min);
    if(k > 0 && k % 2 == 1)
        sum -= (min * 2);

    return sum;
}
