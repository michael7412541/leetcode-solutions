int findMaxConsecutiveOnes(int* nums, int numsSize) {
    if(nums == NULL)
        return -1;
    int i = 0, k = 0, answer = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != 0)
        {
            k++;
        }
        else
        {
            if(k >= answer)
                answer = k;
            k = 0;
        }
        if(k >= answer)
            answer = k;
    }
    return answer;
}
