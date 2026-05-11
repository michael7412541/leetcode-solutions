int longestOnes(int* nums, int numsSize, int k) {
    int answer = 0, right = 0, left = 0, hash[2] = {0};
    for(right = 0; right < numsSize; right++){
        hash[nums[right]]++;
        while(hash[0] > k){
            hash[nums[left]]--;
            left++;
        }
        if(right - left + 1 > answer){
            answer = right - left + 1;
        }
    }
    return answer;
}
