void dfs(int k, int graph[][50], int degree[], int *visited, int *node, int *edge){
    if(visited[k] == 1)
        return;
    visited[k] = 1;
    (*node)++;
    (*edge)+= degree[k];
    int sum = 1; 
    for(int i = 0; i < degree[k]; i++){
        dfs(graph[k][i], graph, degree, visited, node, edge);
    }

}
int countCompleteComponents(int n, int** edges, int edgesSize, int* edgesColSize) {
   int *visited = malloc(sizeof(int) * n);
   int graph[50][50] = {0};
   int degree[50] = {0};
   int edge = 0, node = 0, count = 0;
   memset(visited, 0, sizeof(int) * n );
   for(int i = 0; i < edgesSize; i++){
    graph[edges[i][0]][degree[edges[i][0]]++] = edges[i][1];
    graph[edges[i][1]][degree[edges[i][1]]++] = edges[i][0];
   }
   for(int i = 0; i < n; i++){
    edge = 0;
    node = 0;
    if(visited[i] == 0){
        dfs(i, graph, degree, visited, &node, &edge);
        if(edge == node * (node - 1))
            count++;
    }
   }
   return count;
}
