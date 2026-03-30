void reverse(int *nums, int size){
    int left = 0, right = size - 1;
    while(left < right){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        
        left++;
        right--;
    }
}


void rotate(int* nums, int numsSize, int k) {
    int shift = k % numsSize;
    reverse(nums, numsSize);
    reverse(nums, shift);
    reverse(&nums[shift], numsSize - shift);

}
