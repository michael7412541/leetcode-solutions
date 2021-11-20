

int numSubarrayBoundedMax(int* nums, int numsSize, int left, int right){
    int i = 0, length = 0, count = 0, small = 0;
    for(i = 0; i < numsSize; i++){
        if(nums[i] <= right){            
            count = count + 1;
            if(i == numsSize - 1){
                if(count % 2 == 0)
                    length = length + count/2 * (count + 1);
                else
                    length = length + count * (count + 1)/2;    
            }
                
            
        }
        else{
            if(count % 2 == 0)
                    length = length + count/2 * (count + 1);
            else
                    length = length + count * (count + 1)/2;
            count = 0;
            
        }
        
    }
    count = 0;
    for(i = 0; i < numsSize; i++){
        if(nums[i] < left){            
            count = count + 1;
            if(i == numsSize - 1)
                if(count % 2 == 0)
                    length = length - count/2 * (count + 1);
                else
                    length = length - count * (count + 1)/2;
        }
        else{
            if(count % 2 == 0)
                    length = length - count/2 * (count + 1);
                else
                    length = length - count * (count + 1)/2;
            count = 0;   
        }   
    }
    
    
    return length;
}
