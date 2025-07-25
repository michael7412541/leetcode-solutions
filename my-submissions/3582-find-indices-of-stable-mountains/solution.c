/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* stableMountains(int* height, int heightSize, int threshold, int* returnSize) {
    int *answer = (int*)malloc(sizeof(int)*heightSize);
    int i = 0, count = 0;
    for(i = 0; i < heightSize; i++){
        if(i >= 1 && height[i-1] > threshold){
            answer[count] = i;
            count++;
        }
    }
    *returnSize = count;
    return answer;
}
