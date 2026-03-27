void heapify(int *heap, int size, int index){
    int smallest;
    while(1){
        int L = index * 2 + 1;
        int R = index * 2 + 2;
        
        smallest = index;
        if(L < size && heap[L] > heap[smallest])
            smallest = L;
        
        if(R < size && heap[R] > heap[smallest])
            smallest = R;
        
        if(smallest == index)
            break;
        
        int temp = heap[smallest];
        heap[smallest] = heap[index];
        heap[index] = temp;
        
        index = smallest;
        
    }
    return;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int size = numsSize, answer;
    
    for(int i = numsSize/2 - 1; i >= 0; i--){
        heapify(nums, size, i);
    }
    
    for(int i = 0; i < k; i++){
        answer = nums[0];
        nums[0] = nums[size - 1];
        size--;
        heapify(nums, size, 0);
    }
    
    return answer;
}
