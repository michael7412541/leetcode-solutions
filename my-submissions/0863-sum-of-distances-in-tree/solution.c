/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Edge{
    int to;
    struct Edge *next;
};
int calculate_size(struct Edge **graph, int index, int parent, int *size, int *subtree){

    size[index] = 1;

    for(struct Edge *e = graph[index]; e; e = e->next){
        if(e->to == parent)
            continue;
        size[index] += calculate_size(graph, e->to, index, size, subtree);
        subtree[index] += subtree[e->to];
        subtree[index] += size[e->to];
    }
    return size[index];
}

void calculate_answer(struct Edge **graph, int index, int parent, int *answer, int *size, int *subtree, int n){
    if(index != 0)
        answer[index] = answer[parent] - size[index] + (n - size[index]);
    
    for(struct Edge *e = graph[index]; e; e = e->next){
        if(e->to == parent)
            continue;
        calculate_answer(graph, e->to, index, answer, size, subtree, n);
    }
    
}


int* sumOfDistancesInTree(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    struct Edge **graph = malloc(sizeof(struct Edge*)*n);
    int *answer = malloc(sizeof(int) * n);
    int *size = malloc(sizeof(int) * n);
    int *subtree = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        graph[i] = NULL;
        answer[i] = 0; 
        size[i] = 0;
        subtree[i] = 0;
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
    calculate_size(graph, 0, n+1, size, subtree);
    
    answer[0] = subtree[0];
    calculate_answer(graph, 0, n+1, answer, size, subtree, n);
    *returnSize = n;
    return answer; 
}
