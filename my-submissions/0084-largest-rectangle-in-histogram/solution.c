int largestRectangleArea(int* heights, int heightsSize) {
    int right[heightsSize], left[heightsSize], stack[heightsSize],stack1[heightsSize], top = -1, max = 0;
    for(int i = 0; i < heightsSize; i++){
        right[i] = heightsSize;
        left[i] = -1;
    }
    
    for(int i = 0; i < heightsSize; i++){
        if(top == -1){
            stack[++top] = i;
        }
        else{
        while(top >= 0 && heights[i] < heights[stack[top]]){
            right[stack[top]] = i;
            top--;
        }
        stack[++top] = i;
        }
    }
    top = -1;
    for(int i = 0; i < heightsSize; i++){
        if(top == -1){
            stack1[++top] = heightsSize - i - 1;
        }
        else{
        while(top >= 0 && heights[heightsSize - i - 1] < heights[stack1[top]]){
            left[stack1[top]] = heightsSize - i - 1;
            top--;
        }
        stack1[++top] = heightsSize - i - 1;
        }
    }
    
    for(int i = 0; i < heightsSize; i++){
        if(heights[i] * (right[i] - left[i] - 1) > max)
            max = heights[i] * ( right[i] - left[i] - 1);
    }
    return max;
}
