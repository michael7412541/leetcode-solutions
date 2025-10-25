int search(int* nums, int numsSize, int target) {
    int middle = 0, left = 0, right = numsSize - 1;
    //if(numsSize == 1)
      //  return target == nums[0] ? 0 : -1;
    while(left <= right) {
        middle = (right + left)/2;
        if(target == nums[middle])
            return middle;
        else if(target > nums[middle]) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return -1;
}
