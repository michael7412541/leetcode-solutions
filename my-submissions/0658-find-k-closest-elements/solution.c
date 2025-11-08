/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    //總結一句話（你記住這句就會了）
    //比較窗口左外元素 arr[mid] 和窗口右外元素 arr[mid+k] 哪個離 x 比較遠。
    //左邊遠 → 窗口往右移。
    //右邊遠 → 窗口往左收。
    int mid, left = 0, right = arrSize - k;//尋找最左邊的端點 
    
    while(left < right){
        mid = left + (right -left)/2;
        if(x - arr[mid] > arr[mid + k] - x)
            left = mid + 1;
        else
            right = mid;
    }
    
    int *answer = malloc(sizeof(int)*k);
    for(int i = 0; i < k; i++){
        answer[i] = arr[left + i];
    }
    *returnSize = k;
    return answer;
}
