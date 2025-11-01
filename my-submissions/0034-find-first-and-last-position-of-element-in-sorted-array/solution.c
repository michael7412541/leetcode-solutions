/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int right = numsSize - 1, left = 0, middle = 0;
    int *answer = malloc(sizeof(int)*2);
    
    bool find = false;
    while(left <= right){
        middle = left + (right -left)/2;
        if(nums[middle] < target){
            left = middle + 1;
        }
        else if(nums[middle] == target){
            find = true;
            break;
        }
        else{
            right = middle - 1;
        }
    }
    if(find == true){
        int L = left, M = 0, R = middle, min, max;
        while(L < R){
            M = (L + R - 1)/2;
            if(nums[M] == target){
                R = M;
            }
            else{
                L = M + 1;
            }
        }
        min = L;
        L = middle;
        R = right;
        while(L < R){
            M = (L + R + 1)/2;
            if(nums[M] == target){
                L = M;
            }
            else{
                R = M - 1;
            }
        }
        max = R;
            
        answer[0] = min;
        answer[1] = max;
    }
    else{
        answer[0] = -1;
        answer[1] = -1;
    }
    *returnSize = 2;
    
    return answer;
}
