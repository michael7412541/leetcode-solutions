/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    int *answer = malloc(sizeof(int) * arrSize), max = INT_MIN;
    for(int i = arrSize - 1; i >= 0; i--){
        if(i == arrSize - 1){
            answer[i] = -1;
        }
        else{
            answer[i] = max;
        }

        if(arr[i] > max)
            max = arr[i];
    }
    *returnSize = arrSize;
    return answer;
}
