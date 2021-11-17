

int getMaxLen(int* nums, int numsSize){
    int length1 = 0, length2 = 0, max = 0, num_n1 = 0,num_n2 = -1, temp1 = 0, temp2 = -1, start = 0, ns = 0;
    for(int x = 0; x < numsSize; x++){
        if(nums[x] > 0){
            
            if(num_n1 % 2 == 0){
                length1 = length1 + 1;
            }
            else{
                temp1 = temp1 + 1;
            }
            //start = 0;
            if(num_n2 >= 0){
                if(num_n2 % 2 == 0){
                    length2 = length2 + 1;
                }
                else{
                    temp2 = temp2 + 1;
                }
            }
            
        }
        else if(nums[x] < 0){
            num_n1++;
            //printf("x=%d num[%d]=%d, start = %d\n", x,x-1,nums[x-1],start);
           /* if(x == 0 || nums[x-1] == 0 ){
                temp2 = 1;
                num_n2 = 1;
                printf("*");
                start = 0;
            }
            else if(num_n2 > 0){
                num_n2++;
                if(num_n2 % 2 == 0){
                    length2 = length2 + temp2 + 1;
                    temp2 = 0;
                }
                else{
                    temp2 = temp2 + 1;
                }
                
            } */
            //printf("num[%d] = %d num_n2 = %d temp2 = %d length2 = %d\n", x, nums[x], num_n2, temp2,  length2);
            //start = 0;
            if(x == 0 || nums[x-1] == 0 ){
                temp2 = 0;
                num_n2 = 0;
                printf("*");
            }
            else{
                num_n2++;
                if(num_n2 % 2 == 0){
                length2 = length2 + temp2 + 1;
                temp2 = 0;
            }
            else{
                temp2 = temp2 + 1;
            }
            }
            
            
            
            
            if(num_n1 % 2 == 0){
                length1 = length1 + temp1 + 1;
                temp1 = 0;
            }
            else{
                temp1 = temp1 + 1;
            }
            
            start = 0;
            
        }
        else{
            num_n1 = 0;
            num_n2 = -1;
            temp1 = 0;
            temp2 = -1;
            length1 = 0;
            length2 = 0;
            
        }
        //printf("num[%d] = %d temp1 = %d length1 = %d\n", x, nums[x],temp1,  length1);
        //printf("num[%d] = %d temp2 = %d length2 = %d\n", x, nums[x],temp2,  length2);
        if(length1 > max)
            max = length1;
        if(length2 > max)
            max = length2;
        
    }
    
    
    
    return max;
    
}
