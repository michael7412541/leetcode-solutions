void dfs(int i, int **isConnected, int size, int *visited){
    visited[i] = 1;
    for(int k = 0; k < size; k++){
        if(isConnected[i][k] == 1 && visited[k] == 0){
            dfs(k, isConnected, size, visited);    
        }
    }
}
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int count = 0, *visited = malloc(sizeof(int) * isConnectedSize);
    memset(visited, 0, sizeof(int) * isConnectedSize);
    for(int i = 0; i < isConnectedSize; i++){
        if(visited[i] == 0 && isConnected[i][i] == 1){
            dfs(i, isConnected, isConnectedColSize[i], visited);
            count++;
        }
    }
    return count;
}
