int calculate(int *num, int size){
    int left[size];
    int right[size];
    int stack[size];
    int answer = 0, top = -1;
    for(int i = 0; i < size; i++){
        left[i] = -1;
        right[i] = size;
    }
    for(int i = 0; i < size; i++){
        while(top >= 0 && num[i] < num[stack[top]]){
            right[stack[top--]] = i;
        }
        stack[++top] = i;
    }
    top = -1;
    for(int i = size - 1; i >= 0; i--){
        while(top >= 0 && num[i] < num[stack[top]]){
            left[stack[top--]] = i;
        }
        stack[++top] = i;
    }

    for(int i = 0; i < size; i++){
        int temp = (right[i] - left[i] - 1) * num[i]; 
        if(temp > answer)
            answer = temp;
    }
    return answer;
}
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    int *num = malloc(sizeof(int) * matrixColSize[0]);
    int answer = 0, temp = 0;
    memset(num, 0, sizeof(int) * matrixColSize[0]);
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixColSize[0]; j++){
            if(i == 0)
                num[j] = (int)matrix[i][j] - '0';
            else{
                if(matrix[i][j] == '0')
                    num[j] = 0;
                else
                    num[j] += 1;
            }
        }
        temp = calculate(num, matrixColSize[0]);
        if(temp > answer)
            answer = temp;
        
    }
    return answer;
    
}