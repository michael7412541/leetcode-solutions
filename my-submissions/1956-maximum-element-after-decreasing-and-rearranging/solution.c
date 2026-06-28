// 用於 qsort 的比較函數
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize) {
    if (arr == NULL || arrSize == 0) return 0;
    
    // 1. 先排序，這樣才能貪心地讓小的排前面，大的排後面
    qsort(arr, arrSize, sizeof(int), compare);
    
    // 2. 條件一：第一個元素必須是 1
    int current_max = 1; 
    
    // 3. 從第二個元素開始遍歷
    for (int i = 1; i < arrSize; i++) {
        // 條件二：下一個元素最多只能比當前大 1
        if (arr[i] > current_max) {
            current_max++; // 如果它夠大，我們就可以順理成章地把最大值推進 1 階
        }
        // 如果 arr[i] <= current_max，代表這個數字不夠大，沒辦法幫我們墊高最大值，current_max 維持原狀
    }
    
    return current_max;
}
