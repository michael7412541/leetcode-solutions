int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int memory[100][100];
    memset(memory, -1, sizeof(memory));
    if(obstacleGrid[0][0] == 1)
        return 0;

    for(int i = 0; i < obstacleGridSize; i++){
        for(int j = 0; j < obstacleGridColSize[0]; j++){
            if(memory[i][j] == -1){
                if(obstacleGrid[i][j] == 1)
                    memory[i][j] = 0;
                else if(i == 0 && j == 0)
                    memory[0][0] = 1;
                else if(i == 0)
                    memory[i][j] = memory[i][j-1];
                else if(j == 0)
                    memory[i][j] = memory[i-1][j];
                else
                    memory[i][j] = memory[i-1][j] + memory[i][j-1];
            }
        }
    }

    return memory[obstacleGridSize - 1][obstacleGridColSize[0] - 1];
}
