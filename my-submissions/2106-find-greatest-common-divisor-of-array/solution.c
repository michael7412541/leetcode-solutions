void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int gcd(int a, int b){
    if(a < b) swap(&a, &b);
    if(a % b == 0)
        return b;
    return gcd(a % b, b);
}
int findGCD(int* nums, int numsSize) {
    int min = 1001, max = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > max)
            max = nums[i];
        if(nums[i] < min)
            min = nums[i];
    }

    return gcd(max, min);
}
