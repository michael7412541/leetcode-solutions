void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int removeDuplicates(int* nums, int numsSize) {
    if(nums == NULL)
        return -1;
    int i = 0, k = i+1, count = 0;
    while(i < numsSize)
    {
        k = i + 1;
        if(k < numsSize && nums[k] == nums[i])
        {
            i++;   
        }
        else
        {
            nums[count] = nums[i];
            //printf("i = %d, nums[%d] = %d \n",i,k,nums[k] );
            i++;
            count++;
            
        }
    }
    return count;
}
