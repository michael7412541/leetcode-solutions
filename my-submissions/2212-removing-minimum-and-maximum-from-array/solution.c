int min_ans(int a, int b, int c){
    if(a <= b && a <= c) return a;
    if(b <= a && b <= c) return b;
    return c;
}
int minimumDeletions(int* nums, int numsSize) {
    int max = INT_MIN, min = INT_MAX, max_idx = 0, min_idx = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > max){
            max = nums[i];
            max_idx = i;
        }
        if(nums[i] < min){
            min = nums[i];
            min_idx = i;
        }
    }
    if(max_idx == min_idx)
        return 1;
    
    if(max_idx < min_idx){
        int temp = min_idx;
        min_idx = max_idx;
        max_idx = temp;
    }
        
    //printf("%d %d %d", numsSize, max_idx, min_idx);
    
    int cand1 = max_idx + 1;

    int cand2 = numsSize - min_idx;
    
    int cand3 = min_idx + numsSize - max_idx + 1;
    //printf("\n %d %d %d", cand1, cand2, cand3);
    return min_ans(cand1, cand2, cand3);
}
