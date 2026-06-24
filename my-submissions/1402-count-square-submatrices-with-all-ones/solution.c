int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    int record[matrixSize][matrixColSize[0]], d, h, v, answer = 0, temp;
    memset(record, 0, sizeof(record));
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixColSize[i]; j++){
            if(matrix[i][j] == 1){
                d = i > 0 && j > 0 ? record[i-1][j-1] : 0;
                h = j > 0 ? record[i][j-1] : 0;
                v = i > 0 ? record[i-1][j] : 0;
                temp = d;
                if(h < temp) temp = h;
                if(v < temp) temp = v;

                record[i][j] = temp + 1;
            }
            answer += record[i][j];
        }
    }
    return answer;
}
