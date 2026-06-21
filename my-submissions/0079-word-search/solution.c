bool dfs(int **visited, char **board, int x, int y, int x_size, int y_size, char *word, int word_size,  int pos){
    if(x >= x_size || y >= y_size || x < 0 || y < 0)
        return false;

    


    if(pos < word_size && word[pos] != board[x][y])
        return false;

    if(visited[x][y] == 1)
        return false;
    
    visited[x][y] = 1;

    if(pos == word_size - 1)
        return true;
    
    bool up = dfs(visited, board, x + 1, y, x_size, y_size, word, word_size, pos+1);
    bool down = dfs(visited, board, x - 1, y, x_size, y_size, word, word_size, pos+1);
    bool left = dfs(visited, board, x, y + 1, x_size, y_size, word, word_size, pos+1);
    bool right = dfs(visited, board, x, y - 1, x_size, y_size, word, word_size, pos+1);

     visited[x][y] = 0;
    return (up || down || left || right);

}
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int size = strlen(word);
    int **visited = malloc(sizeof(int*) * boardSize);

     for(int i = 0; i < boardSize; i++){
        visited[i] = malloc(sizeof(int) * boardColSize[i]);
        for(int j = 0; j < boardColSize[i]; j++){
            visited[i][j] = 0;
        }
     }

    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardColSize[i]; j++){
            if(board[i][j] == word[0]){
                bool answer = dfs(visited, board, i, j, boardSize, boardColSize[i], word, size, 0);
                if(answer)
                    return answer;
            }
        }
    }

    free(visited);

    return false;
}
