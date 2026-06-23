int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    int record[100][100], c1, c2, c3, temp, answer = INT_MAX;
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixColSize[0]; j++){
            if(i == 0)
                record[i][j] = matrix[i][j];
            else{
            c1 = (i > 0 && j > 0) ? record[i-1][j-1] : INT_MAX;
            c2 = (i > 0) ? record[i-1][j] : INT_MAX;
            c3 = (i > 0 && j + 1 < matrixColSize[i]) ? record[i-1][j+1] : INT_MAX;
            temp = c1;
            if(c2 < c1) temp = c2;
            if(c3 < temp) temp = c3;

            record[i][j] = matrix[i][j] + temp;

            
            }

            if((i == matrixSize - 1) && (record[i][j] < answer))
                answer = record[i][j];
        }
    }
    return answer;
}
