void dfs(char **board, int x_size, int y_size, int x1, int y1){
    if(x1 < 0 || x1 >= x_size || y1 < 0 || y1 >= y_size)
        return;
    if(board[x1][y1] != 'O')
        return;
    
    board[x1][y1] = 'A';

    dfs(board, x_size, y_size, x1 + 1, y1);
    dfs(board, x_size, y_size, x1 - 1, y1);
    dfs(board, x_size, y_size, x1, y1 + 1);
    dfs(board, x_size, y_size, x1, y1 - 1);
}
void solve(char** board, int boardSize, int* boardColSize) {
    if(board == NULL || boardSize == 0 || boardColSize == NULL)
        return;

    for(int i = 0; i < boardSize; i++){
        if(board[i][0] == 'O'){
            dfs(board, boardSize, boardColSize[0], i, 0);
        }
        if(board[i][boardColSize[0] - 1] == 'O'){
            dfs(board, boardSize, boardColSize[0], i, boardColSize[0] - 1);
        }
    }
    for(int j = 0; j < boardColSize[0]; j++){
        if(board[0][j] == 'O'){
            dfs(board, boardSize, boardColSize[0], 0, j);
        }
        if(board[boardSize - 1][j] == 'O'){
            dfs(board, boardSize, boardColSize[0], boardSize - 1, j);
        }
    }
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardColSize[0]; j++){
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            else if(board[i][j] == 'A')
                board[i][j] = 'O';
        }
    }
}
