struct Edge{
    int to;
    struct Edge *next;
};
int count = 0, answer = 0;
void dfs(struct Edge **graph, struct Edge **guessGraph, int parent, int index){
    if(graph[index] == NULL){
        return ;
    }
    for(struct Edge *u = graph[index]; u; u = u->next){
        if(u->to == parent)
            continue;
        
        for(struct Edge *v = guessGraph[index]; v; v = v->next){
            if(u->to == v->to){
                count++;
                break;
            }
        }
        dfs(graph, guessGraph, index, u->to);
    }

}

void dfs1(struct Edge **graph, struct Edge **guessGraph, int parent, int index, int k){
    if(graph[index] == NULL){
        return ;
    }
    
    for(struct Edge *u = graph[index]; u; u = u->next){
        if(u->to == parent)
            continue;
        int temp = count;
        for(struct Edge *v = guessGraph[index]; v; v = v->next){
            if(u->to == v->to){
                count--;
                break;
            }
        }

        for(struct Edge *v = guessGraph[u->to]; v; v = v->next){
            if(index == v->to){
                count++;
                break;
            }
        }
        if(count >= k)
            answer++;
        
        dfs1(graph, guessGraph, index, u->to, k);
        count = temp;
    }

}



int rootCount(int** edges, int edgesSize, int* edgesColSize, int** guesses, int guessesSize, int* guessesColSize, int k) {
    struct Edge **graph = malloc(sizeof(struct Edge)*edgesSize*2), **guessGraph = malloc(sizeof(struct Edge) * edgesSize*2);
    for(int i = 0; i < edgesSize*2; i++){
        graph[i] = NULL;
        guessGraph[i] = NULL;
    }
    for(int i = 0; i < edgesSize; i++){
        int to = edges[i][0];
        int from = edges[i][1];
        struct Edge *new = malloc(sizeof(struct Edge));
        new->to = to;
        new->next = graph[from];
        graph[from] = new;
        struct Edge *new1 = malloc(sizeof(struct Edge));
        new1->to = from;
        new1->next = graph[to];
        graph[to] = new1;
    }
    for(int i = 0; i < guessesSize; i++){
        int from = guesses[i][0];
        int to = guesses[i][1];
        struct Edge *new = malloc(sizeof(struct Edge));
        new->to = to;
        new->next = guessGraph[from];
        guessGraph[from] = new;
    }
    count = 0;
    answer = 0;
    dfs(graph, guessGraph, -1, 0);

    if(count >= k)
        answer++;

    dfs1(graph, guessGraph, -1, 0, k);
    
    return answer;
}
