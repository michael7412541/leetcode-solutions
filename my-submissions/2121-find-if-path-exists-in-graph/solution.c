/*bool helper(int **edges, int edgesSize, int source, int destination, int *visited){
    int target;
    bool answer = false;

    if(visited[source] == 1)
        return false;

    visited[source] = 1;

    if(source == destination)
        return true;

    for(int i = 0; i < edgesSize; i++){
        if(source == edges[i][0]){
            target = edges[i][1];
            answer = helper(edges, edgesSize, target, destination, visited);
        }
        else if(source == edges[i][1]){
            target = edges[i][0];
            answer = helper(edges, edgesSize, target, destination, visited);
        }
        
        if(answer == true)
            return answer;
    }
    return false;
}
bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    int *visited = malloc(sizeof(int) * n);
    memset(visited, 0, sizeof(int) * n);

    return helper(edges, edgesSize, source, destination, visited);
}*/
typedef struct Edge{
    int to;
    struct Edge *next;
} Edge;

bool helper(Edge **graph, int start, int destination, int *visited){
    if(visited[start] == 1)
        return false;

    visited[start] = 1;
    if(start == destination)
        return true;

    for(Edge *e = graph[start]; e; e = e->next){
        if(helper(graph, e->to, destination, visited)) 
            return true;
    }
    return false;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {

    Edge **graph = malloc(sizeof(Edge*) * n);
    int *visited = malloc(sizeof(int) * n);
    int from = 0, to = 0, start = -1;
    for(int i = 0; i < n; i++){
        graph[i] = NULL;
        visited[i] = 0;
    }
    for(int i = 0; i < edgesSize; i++){
        from = edges[i][0];
        to = edges[i][1];
        Edge *new = malloc(sizeof(Edge));
        new->to = to;
        new->next = graph[from];
        graph[from] = new;

        Edge *new1 = malloc(sizeof(Edge));
        new1->to = from;
        new1->next = graph[to];
        graph[to] = new1;



    }

    return helper(graph, source, destination, visited);
}


