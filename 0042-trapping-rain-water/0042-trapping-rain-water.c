int min(int a, int b){
    return a < b ? a : b;
}
int trap(int* height, int heightSize) {
    int left[heightSize];
    int right[heightSize];
    int stack[heightSize];
    int answer = 0, top = -1;
    for(int i = 0; i < heightSize; i++){
        left[i] = 0;
        right[i] = 0;
    }
    int max = 0;
    for(int i = 0; i < heightSize; i++){
        if(height[i] > max){
            max = height[i];
        }
        left[i] = max;
    }
    max = 0;
    for(int i = heightSize - 1; i >= 0; i--){
        if(height[i] > max){
            max = height[i];
        }
        right[i] = max;
    }

    /*top = -1;
    for(int i = heightSize - 1 ; i >= 0; i--){
        while(top >= 0 && height[i] > height[stack[top]]){
            left[stack[top--]] = height[i];
        }
        stack[++top] = i;
    }*/
    for(int i = 0; i < heightSize; i++){
        //printf("left = %d, right = %d\n", left[i], right[i]);
        if(left[i] != 0 && right[i] != 0){
            //printf("i = %d, %d\n", i, min(left[i], right[i]) - height[i]);
            answer += (min(left[i], right[i]) - height[i]);
        }
    }
    return answer;
}