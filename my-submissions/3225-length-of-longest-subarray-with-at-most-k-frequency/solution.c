#define RANGE 1000000
int maxSubarrayLength(int* nums, int numsSize, int k) {
    long long hash[RANGE] = {0};

    int answer = INT_MIN;
    long long left = 0, right;
    for(right = 0; right < numsSize; right++){
        int index = nums[right]%100007;
        hash[index]++;
        while(hash[index] > k){
            hash[nums[left++]%100007]--; 
        }
        if(right - left + 1 > answer)
            answer = right - left + 1;
    }
    return answer;
}
