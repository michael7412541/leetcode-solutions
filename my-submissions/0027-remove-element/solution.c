int remove_1(int index, int* nums, int numsSize, int val, int x){
    int i;
    for(i = 0; i < numsSize; i++)
        printf("%d, ", nums[i]);
    printf("\n");
    if(nums[index] == val ){
        x++;
        //printf("Find!!! nums[%d] = %d\n", index, nums[index]);
        if(index == numsSize - 1){
            nums[index] = 0; 
        }
        else{
            for(i = index; i < numsSize - x; i++)
                nums[i] = nums[i + 1];
            for(i = numsSize - x; i < numsSize; i++)
                nums[i] = 0;
        }
        if(index == 0)
            return x;
        else
            return remove_1(index - 1, nums, numsSize, val, x);
    }
    else{
        printf("No!!! nums[%d] = %d\n", index, nums[index]);
        if(index == 0)
            return x;
        else
            return remove_1(index - 1, nums, numsSize, val, x);
    }
}
int removeElement(int* nums, int numsSize, int val){
    int i = 0, count = 0, y;
    if(numsSize > 0){
        y = remove_1(numsSize - 1, nums, numsSize, val, count);
        printf("%d", y);
        return numsSize - y;
    }
    else{
        return 0;
    }
}


