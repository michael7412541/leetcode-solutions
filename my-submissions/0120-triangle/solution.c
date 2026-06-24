int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int record[triangleSize], left, right , temp, answer = INT_MAX;
    record[0] = triangle[0][0];
    if(triangleSize == 1)
        return triangle[0][0];
    for(int i = 1; i < triangleSize; i++){
        for(int j = triangleColSize[i]-1; j >=0 ; j--){
            left = j - 1 >= 0 ? record[j-1] : INT_MAX;
            right =j < triangleColSize[i-1] ?  record[j] : INT_MAX;
            temp = left > right ? right : left;
            
            record[j] = temp + triangle[i][j];
            //printf("left = %d, right = %d, record[%d] = %d\n", left, right, j, record[j]);
            if(i == triangleSize - 1 && record[j] < answer)
                answer = record[j];
        }
    }

    return answer;
}
