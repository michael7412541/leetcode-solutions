/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Edge{
    int to;
    struct Edge *next;
};

void dfs_distance(int *size, struct Edge **graph, int index, int parent, int *answer, int n){
    if(graph[index] == NULL){
        return ;
    }
    
    for(struct Edge *e = graph[index]; e; e = e->next){
        int to = e->to;
        if(parent == to)
            continue;
        
        answer[to] = answer[index] - size[to] + (n - size[to]);
        dfs_distance(size, graph, to, index, answer, n);
    }
    
}

int dfs_size(int *size, struct Edge **graph, int index, int parent, int *answer){
    if(graph[index] == NULL){
        size[index] = 1;
        return 1;
    }
    size[index] = 1;
    for(struct Edge *e = graph[index]; e; e = e->next){
        int to = e->to;
        if(to == parent)
            continue;
        size[index] += dfs_size(size, graph, to, index, answer);
        answer[index] += size[to] + answer[to];  
    }
    return size[index];
}

int* sumOfDistancesInTree(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    struct Edge **graph = malloc(sizeof(struct Edge*) * n);
    int *size = malloc(sizeof(int)*n);
    int *answer = malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        graph[i] = NULL;
        answer[i] = 0;
        size[i] = 0;
    }

    for(int i = 0; i < edgesSize; i++){
        int from = edges[i][0];
        int to = edges[i][1];
        struct Edge *new = malloc(sizeof(struct Edge));
        new->to = to;
        new->next = graph[from];
        graph[from] = new;

        struct Edge *new1 = malloc(sizeof(struct Edge));
        new1->to = from;
        new1->next = graph[to];
        graph[to] = new1;
    }

    int temp = dfs_size(size, graph, 0, -1, answer);
    dfs_distance(size, graph, 0, -1, answer, n);
    *returnSize = n;
    return answer;
}
