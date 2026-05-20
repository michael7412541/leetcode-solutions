void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int removeDuplicates(int* nums, int numsSize) {
    int prev = -1, fast = 0, slow = -1, count = 1;
    for(fast = 0; fast < numsSize; fast++){
        if(nums[fast] != prev){
            slow++;
            count = 1;
        }
        else{
            count++;
            if(count <= 2){
                slow++;
                
            }
        }
        nums[slow] = nums[fast];
        prev = nums[fast];
    }
    return slow + 1;
}
