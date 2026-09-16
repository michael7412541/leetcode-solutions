int largestRectangleArea(int* heights, int heightsSize) {
    int left[heightsSize];
    int right[heightsSize];
    int stack[heightsSize], top = -1;
    int answer = 0;
    for(int i = 0; i < heightsSize; i++){
        right[i] = heightsSize;
        left[i] = -1;
    }

    for(int i = 0; i < heightsSize; i++){
        while(top >= 0 && heights[i] < heights[stack[top]]){
            right[stack[top]] = i;
            top--;
        }
        stack[++top] = i;
    }
    top = -1;
    for(int i = heightsSize - 1; i >= 0; i--){
        while(top >= 0 && heights[i] < heights[stack[top]]){
            left[stack[top]] = i;
            top--;
        }
        stack[++top] = i;
    }
    for(int i = 0; i < heightsSize; i++){
        //printf("left[%d] = %d, right[%d] = %d\n", i, left[i], i, right[i]);
        int temp = (right[i] - left[i] - 1) * heights[i]; 
        if(temp > answer)
            answer = temp;
    }
    return answer;
}