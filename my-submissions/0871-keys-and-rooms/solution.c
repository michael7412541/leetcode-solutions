void dfs(int **rooms, int roomsSize, int *roomsColSize, int *visited, int start){
    if(visited[start] == 1)
        return;
    visited[start] = 1;
    for(int i = 0; i < roomsColSize[start]; i++){
        dfs(rooms, roomsSize, roomsColSize, visited, rooms[start][i]);
    }
    
}
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int *visited = malloc(sizeof(int) * roomsSize);
    memset(visited, 0, sizeof(int) * roomsSize);
    dfs(rooms, roomsSize, roomsColSize, visited, 0);

    for(int i = 0; i < roomsSize; i++)
        if(visited[i] == 0)
            return false;
    
    return true;
}
