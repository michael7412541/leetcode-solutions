void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void moveZeroes(int* nums, int numsSize) {
    int i = 0, k = 0;
    while(i < numsSize)
    {
        if(nums[i] == 0)//當下是0 就跟下個非0的數字做交換，然後下次從交換的那個數字的下一個開始
        {
            k = i + 1;
            while(k < numsSize)
            {
                if(nums[k] != 0)
                    break;
                k++;
            }
            if(k < numsSize)
                swap(&nums[i], &nums[k]);
        }
        i++;
    }
}
