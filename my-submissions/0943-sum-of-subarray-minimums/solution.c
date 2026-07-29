int sumSubarrayMins(int* arr, int arrSize) {
    if(arrSize == 1)
        return arr[0];
    int top = -1, stack[arrSize+1], left_min[arrSize], right_min[arrSize];

    memset(left_min, -1, sizeof(int) * arrSize);
    memset(right_min, -1, sizeof(int) * arrSize);
    for(int i = 0; i < arrSize; i++){
        while(top >= 0 && arr[stack[top]] >= arr[i]){
            right_min[stack[top]] = i;
            top--; 
        }
        stack[++top] = i;
    }
    top = -1;

    for(int i = arrSize - 1; i >= 0; i--){
        while(top >= 0 && arr[stack[top]] > arr[i]){
            left_min[stack[top]] = i;
            top--; 
        }
        stack[++top] = i;
    }
    long long sum = 0, contribution = 0;
    for(int i = 0; i < arrSize; i++){
        if(left_min[i] == -1 && right_min[i] == -1){
            contribution = (long long)arr[i] * (i + 1) * (arrSize - i);
        }
        else if(left_min[i] != -1 && right_min[i] != -1){
            contribution = (long long)arr[i] * (right_min[i] - i) * (i - left_min[i]);
        }
        else if(left_min[i] == -1){
            contribution = (long long)arr[i] * (right_min[i] - i) * (i + 1);
        }
        else{
            contribution = (long long)arr[i] * (i - left_min[i]) * (arrSize - i);
        }
        //printf("%d = contri = %d\n", arr[i], contribution);
        sum += contribution;
        sum = sum % 1000000007;
    }
    return (int)sum;
    
}
