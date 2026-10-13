int compare(const void *a, const void *b){
    return *(long long*)a - *(long long*)b;
}
long long maxAlternatingSum(int* nums, int numsSize) {
    long long square[numsSize];
    for(int i = 0; i < numsSize; i++)
        square[i] = nums[i] * nums[i];
    qsort(square, numsSize, sizeof(long long), compare);
    long long answer = 0;
    for(int i = 0; i < numsSize/2; i++){
        answer -= square[i];
    }
    for(int i = numsSize/2; i < numsSize; i++){
        answer += square[i]; 
    }
    return answer;
}