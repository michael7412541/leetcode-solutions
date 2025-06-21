#define DIGITS_NUM  10
void counting_sort(int *nums, int size, long long placeVal)
{
    int counting[10] = {0};
    int i = 0, index = 0;
    for(i = 0; i < size; i++)
    {
        index = (nums[i] / placeVal) % 10;
        counting[index]++;
    }
    for(i = 1; i < 10; i++)
    {
        counting[i] += counting[i-1];
    }
    int *output = (int*)malloc(sizeof(int)*size);
    for(i = size - 1; i >= 0 ; i--)
    {
        index = (nums[i] / placeVal) % 10;
        
        counting[index]--;
        output[counting[index]] = nums[i];
    }
    for(i = 0; i < size; i++)
    {
        
        nums[i] = output[i];
    }
    free(output);
    
}
void radix_sort(int *nums, int size)
{
    int i = 0;
    long long placeVal = 1;
    for(i = 0; i < DIGITS_NUM; i++)
    {
        counting_sort(nums, size, placeVal);
        placeVal *= 10;
    }
}
int maximumGap(int* nums, int numsSize) {
    int i = 0, max_diff = 0;
    radix_sort(nums, numsSize);
    for(i = 0; i < numsSize - 1; i++)
    {
        if(nums[i+1] - nums[i] > max_diff)
            max_diff = nums[i+1] - nums[i];
    }
    return max_diff;
}
