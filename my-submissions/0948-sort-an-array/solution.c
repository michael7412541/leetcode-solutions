/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void heapify(int *heap, int size, int index){
    
    int smallest = index;
    while(1){
        int L = index * 2 + 1;
        int R = index * 2 + 2;
        smallest = index;
        
        if(L < size && heap[L] < heap[smallest])
            smallest = L;
        
        if(R < size && heap[R] < heap[smallest])
            smallest = R;
        
        if(smallest == index)
            break;
        
        int temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;
        
        index = smallest;
    }
    return ;
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    int *answer = malloc(sizeof(int) * numsSize);// min heap
    //int *heap = malloc(sizeof(int) * numsSize);
    int size = numsSize;
    *returnSize = numsSize;
    
    for(int i = numsSize / 2 - 1; i >= 0; i--){
        heapify(nums, numsSize, i);
    }
    
    for(int i = 0; i < numsSize; i++){
        answer[i] = nums[0];
        nums[0] = nums[size - 1];
        size--;
        heapify(nums, size, 0);
    }
    
    return answer;
}
