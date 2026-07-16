void swap(long long *a, long long *b){
    long long temp = *a;
    *a = *b;
    *b = temp;
}
int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
long long gcd(long long a, long long b){
    if(a < b) swap(&a, &b);
    
    if(a % b == 0)
        return b;
    else
        return gcd(a - b * (a/b), b);
}
long long gcdSum(int* nums, int numsSize) {
    int max = -1, *prefixGcd = malloc(sizeof(int) * numsSize);
    memset(prefixGcd, 0, sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > max){
            max = nums[i];
        }
        
        prefixGcd[i] = gcd(max, nums[i]);
    }
    qsort(prefixGcd, numsSize, sizeof(int), compare);
    long long sum = 0;
    int left = 0, right = numsSize -1;
    while(left < right){
        sum += gcd(prefixGcd[left], prefixGcd[right]);
        left++;
        right--;
    }
    return sum;
}
