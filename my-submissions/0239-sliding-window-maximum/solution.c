/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int queue[numsSize], head = -1, tail = -1, count = 0;
    *returnSize = numsSize - k + 1;
    int *answer = malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < numsSize; i++){
        if(head == -1){
            head = 0;
            queue[++tail] = i;
        }
        else{
            while(tail >= head && nums[i] >= nums[queue[tail]]){
                tail--;
            }
            queue[++tail] = i;
        }
        if(i >= k - 1){
            if(i - queue[head] > k - 1){
                head++;
            }
            answer[count++] = nums[queue[head]];
        }

    }
    return answer;
}
