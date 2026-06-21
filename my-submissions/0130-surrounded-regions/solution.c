void dfs(char **board, int x, int y, int x_size, int y_size){
    if(x >= x_size || x < 0 || y >= y_size || y < 0)
        return;
    
    if(board[x][y] != 'O')
        return;
    
    board[x][y] = '@';
    dfs(board, x + 1, y, x_size, y_size);
    dfs(board, x - 1, y, x_size, y_size);
    dfs(board, x, y + 1, x_size, y_size);
    dfs(board, x, y - 1, x_size, y_size);
}

void solve(char** board, int boardSize, int* boardColSize) {
    int i , j, m = boardSize, n = boardColSize[0];
    bool temp;
    for(i = 0; i < m; i++){
        if(board[i][0] == 'O') dfs(board, i, 0, m, n);
        if(board[i][n-1] == 'O') dfs(board, i, n-1, m, n);
    }

    for(j = 0; j < n; j++){
        if(board[0][j] == 'O') dfs(board, 0, j, m, n);
        if(board[m-1][j] == 'O') dfs(board, m-1, j, m, n);
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(board[i][j] == '@')
                board[i][j] = 'O';
        }
    }

}
