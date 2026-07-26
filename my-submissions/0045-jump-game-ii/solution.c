int jump(int* nums, int numsSize) {
    int answer = 0, farthest = 0, currentEnd = 0;
    for(int i = 0; i < numsSize - 1; i++){
        if(farthest < nums[i] + i){
            farthest = nums[i] + i;
        }
        if(i == currentEnd){
            answer++;
            currentEnd = farthest;
        }
        if(currentEnd >= numsSize - 1)
            break;
    }

    return answer;
}
