/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int val;
    int index;
} Node;
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    Node stack[numsSize * 2];
    int top = -1;
    int *answer = malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        answer[i] = -1;
    }
    for(int i = 0; i < numsSize * 2; i++){
        if(top == -1){
            stack[++top].val = nums[i % numsSize];
            stack[top].index = i % numsSize;
        }
        else{
            while(top >= 0 && nums[i % numsSize]  > stack[top].val ){
                answer[stack[top--].index] = nums[i % numsSize];
            }
            stack[++top].val = nums[i % numsSize];
            stack[top].index = i % numsSize;
        }
    }
    
    *returnSize = numsSize;
    return answer;
}
