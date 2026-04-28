/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int stack[2000] = {0}, record[10000] = {0};
    int i = 0, top = -1;
    int *answer = malloc(sizeof(int) * nums1Size);
    for(i = 0; i < nums2Size; i++){
        while(top != -1 && nums2[i] > nums2[stack[top]]){
            record[nums2[stack[top]]] = nums2[i];
            //printf("top = %d\n", top);
            top--;
            //pop
        }
        ///push
        stack[++top] = i;
    }
    for(i = 0; i < nums1Size; i++){
        if(record[nums1[i]] > 0)
            answer[i] = record[nums1[i]];
        else
            answer[i] = -1;
    }
    *returnSize = nums1Size;
    return answer;
}
