/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int **answer = malloc(sizeof(int*) * gridSize);
    int shift = k % gridSize * gridColSize[0], idx_ans;
    *returnColumnSizes = malloc(sizeof(int) * gridSize);
    for(int i = 0; i < gridSize; i++){
        answer[i] = malloc(sizeof(int) * gridColSize[0]);
        (*returnColumnSizes)[i] = gridColSize[0];
    }
    for(int i = 0; i < gridSize * gridColSize[0]; i++){
        idx_ans = (i + k) % (gridSize * gridColSize[0]);
        
        answer[idx_ans/gridColSize[0]][idx_ans%gridColSize[0]] =  grid[i/gridColSize[0]][i%gridColSize[0]];
    }
    *returnSize = gridSize;
    return answer;
}
