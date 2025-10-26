int search(int* nums, int numsSize, int target) {
    int i = 0, shift = 0;
    int temp[numsSize];
    for(i = 1; i < numsSize; i++){
        if(nums[i] < nums[i-1])
            break;
    }
    shift = i;
    for(i = 0; i < numsSize; i++){
        temp[i] = nums[(i + shift) % numsSize];
    }
    for(i = 0; i < numsSize; i++){
        //printf("%d ", temp[i]);
    }
    
    int left = 0, right = numsSize - 1, middle = 0;
    while(left <= right){
        middle = left + (right - left)/2;
        if(temp[middle] > target){
            right = middle - 1;
        }
        else if(temp[middle] < target){
            left = middle + 1;
        }
        else{
            return (middle + shift) % numsSize;
        }
        
    }
    return -1;//non-used
}
