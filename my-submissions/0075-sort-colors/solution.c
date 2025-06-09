void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findmin(int *nums, int start, int size) {
    int i = 0, index = 0, min = 10;
    for(i = start; i < size; i++)
    {
        if(nums[i] < min) {
            min = nums[i];
            index = i;
        }
            
    }
    return index;
}
void sortColors(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)
        return;
    int i = 0, minIndex = 0;
    for(i = 0; i < numsSize; i++)
    {
        minIndex = findmin(nums, i, numsSize);
        swap(&nums[i], &nums[minIndex]);
    }
}
