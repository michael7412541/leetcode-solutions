typedef struct Edge{
    int to;
    struct Edge *next;
}Edge;

void dfs(Edge **graph, int start, int *visited){
    if(visited[start] == 1)
        return;
    visited[start] = 1;
    for(Edge *e = graph[start]; e ;e = e->next){
        dfs(graph, e->to, visited);
    }
}
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int *visited = malloc(sizeof(int) * roomsSize);
    Edge **graph = malloc(sizeof(Edge*) * roomsSize);
    for(int i = 0; i < roomsSize; i++){
        visited[i] = 0;
        graph[i] = NULL;
    }
    for(int i = 0; i < roomsSize; i++){
        for(int j = 0; j < roomsColSize[i]; j++){
            int to = rooms[i][j];
            int from = i;
            Edge *new = malloc(sizeof(Edge));
            new->to = to;
            new->next = graph[from];
            graph[from] = new;  
        }
    }
    dfs(graph, 0, visited);
    for(int i = 0; i < roomsSize; i++){
        if(visited[i] == 0)
            return false;
    }
    return true;
}
