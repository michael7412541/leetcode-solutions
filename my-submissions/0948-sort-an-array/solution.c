/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int *nums, int i, int length)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < length && nums[left] > nums[largest])
        largest = left;
    
    if(right < length && nums[right] > nums[largest])
        largest = right;
    
    if(largest != i)
    {
        swap(&nums[i], &nums[largest]);
        heapify(nums, largest, length);
    }
    
}
int* sortArray(int* nums, int numsSize, int* returnSize) {
    if(nums == NULL || numsSize == 0)
        return NULL;
    int i = 0;
    for(i = numsSize/2 - 1; i >= 0; i--)
    {
        heapify(nums, i, numsSize);
    }
    for(i = numsSize - 1; i > 0; i--)
    {
        swap(&nums[i], &nums[0]);
        heapify(nums, 0, i);
    }
    *returnSize = numsSize;
    return nums;
}
