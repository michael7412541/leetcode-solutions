


typedef struct {
    int *prefix;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *arr = malloc(sizeof(NumArray));
    arr->prefix = malloc(sizeof(int) * (numsSize + 1));
    arr->prefix[0] = 0;
    for(int i = 1; i <= numsSize; i++){
        arr->prefix[i] = arr->prefix[i-1] + nums[i-1];
    }
    return arr;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    if(left > right)
        return 0;

    //printf("left = %d, right= %d\n", left, right);
    
    return obj->prefix[right+1] - obj->prefix[left];
}
// 0 -2 -2 1 -4 -2 -3
//    0  1 2  3  4  5
void numArrayFree(NumArray* obj) {
    free(obj->prefix);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
