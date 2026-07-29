/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int top = -1, stack[nums2Size];
    memset(stack, 0, sizeof(stack));
    *returnSize = nums1Size;
    int idx, *answer = malloc(sizeof(int) * nums1Size), *next = malloc(sizeof(int) * nums2Size);
    memset(next, -1, sizeof(int) * nums2Size);
    stack[++top] = 0;

    for(int i = 1; i < nums2Size; i++){

        while(top >= 0 && nums2[stack[top]] < nums2[i]){
            next[stack[top]] = i;
            top--;
        }
        stack[++top] = i;
    }

    

    for(int i = 0; i < nums1Size; i++){
        for(int j = 0; j < nums2Size; j++){
            if(nums1[i] == nums2[j]){
                answer[i] = next[j] >= 0 ? nums2[next[j]] : -1;
                break;
            }

        }
    }
    return answer;
}
