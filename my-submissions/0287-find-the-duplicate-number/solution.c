int findDuplicate(int* nums, int numsSize) {
    int left = 1, right = numsSize - 1, mid = 0;
    while(left < right){
        mid = left + (right - left)/2;
        int count = 0;
        for(int i = 0; i < numsSize; i++){
            if(nums[i] <= mid)
                count++;
        }
        if(count > mid)
            right = mid;
        else
            left = mid + 1;
            
    }
    return left;
}

// 先計算出中間數 然後看大於的比較多 還是小魚的比較多
// 
