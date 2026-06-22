
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int memory[200][200];
    memset(memory, -1, sizeof(memory));
    memory[0][0] = grid[0][0];
    for(int i = 1; i < gridSize; i++){
        memory[i][0] = memory[i - 1][0] + grid[i][0];
    }

    for(int i = 1; i < gridColSize[0]; i++){
        memory[0][i] = memory[0][i - 1] + grid[0][i];
    }

    for(int i = 1; i < gridSize; i++){
        for(int j = 1; j < gridColSize[i]; j++){
            if(memory[i][j] == -1){
                if(memory[i-1][j] > memory[i][j-1]){
                    memory[i][j] = memory[i][j-1] + grid[i][j];
                }
                else{
                    memory[i][j] = memory[i-1][j] + grid[i][j];
                }
            }
        }
    }
    return memory[gridSize-1][gridColSize[0] - 1];
}
