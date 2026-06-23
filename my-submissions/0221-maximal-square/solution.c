int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    int answer = 0, record[300][300] = {0}, h, v, d;
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixColSize[i]; j++){
            if(matrix[i][j] == '0')
                record[i][j] = 0;
            else
                record[i][j] = 1;
            if(matrix[i][j] == '1'){
                d = (i > 0 && j > 0) ? record[i-1][j-1] : 0;
                h = (i > 0) ? record[i-1][j] : 0;
                v = (j > 0) ? record[i][j-1] : 0;
                if(d <= h && d <= v) record[i][j] = d + 1;
                if(h <= d && h <= v) record[i][j] = h + 1;
                if(v <= h && v <= d) record[i][j] = v + 1;

                if(record[i][j] > answer)
                    answer = record[i][j];
            }
        }
    }
    return answer * answer;
}
