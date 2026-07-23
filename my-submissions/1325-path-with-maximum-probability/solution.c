typedef struct {
    int node;
    double prob;
} HeapNode;

struct Edge{
    int to;
    double prob;
    struct Edge *next;
};

typedef struct {
    HeapNode *data;
    int size;
    int capacity;
} MaxHeap;

void swap(HeapNode *a, HeapNode *b){
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(MaxHeap *queue, int node){
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int big = node;
    if(left < queue->size && queue->data[left].prob > queue->data[big].prob){
        big = left;
    }

    if(right < queue->size && queue->data[right].prob > queue->data[big].prob){
        big = right;
    }
    if(node != big){
        swap(&queue->data[node], &queue->data[big]);
        heapifyDown(queue, big);
    } 
}

void heapifyUp(MaxHeap *queue, int node){
    int parent = (node - 1)/2;
    if(queue->data[parent].prob < queue->data[node].prob){
        swap(&queue->data[parent], &queue->data[node]);
        heapifyUp(queue, parent);
    }
}

void push(MaxHeap *queue, int node, double prob){
    HeapNode new;
    new.node = node;
    new.prob = prob;
    queue->data[queue->size++] = new;
    heapifyUp(queue, queue->size-1);
}

HeapNode pop(MaxHeap *queue){
    HeapNode result = queue->data[0];
    queue->data[0] = queue->data[--queue->size];
    heapifyDown(queue, 0);
    return result;
}

double maxProbability(int n, int** edges, int edgesSize, int* edgesColSize, double* succProb, int succProbSize, int start_node, int end_node) {
    struct Edge **graph = malloc(sizeof(struct Edge*) * n);
    for(int i = 0; i < n; i++){
        graph[i] = NULL;
    }
    for(int i = 0; i < edgesSize; i++){
        int from = edges[i][0];
        int to = edges[i][1];
        struct Edge *new = malloc(sizeof(struct Edge));
        new->to = to;
        new->prob = succProb[i];
        new->next = graph[from];
        graph[from] = new;

        struct Edge *new2 = malloc(sizeof(struct Edge));
        new2->to = from;
        new2->prob = succProb[i];
        new2->next = graph[to];
        graph[to] = new2;

    }
    MaxHeap *queue = malloc(sizeof(MaxHeap));
    queue->data = malloc(sizeof(HeapNode)*20000);
    queue->size = 0;
    HeapNode new;
    new.node = start_node;
    new.prob = 1;
    queue->data[queue->size++] = new;
    double prob[n];
    for(int i = 0; i < n; i++){
        prob[i] = 0;
    }
    prob[start_node]  = 1;
    while(queue->size > 0){
        HeapNode cur = pop(queue);
        if(cur.prob < prob[cur.node])
            continue;
        for(struct Edge *e = graph[cur.node]; e; e = e->next){
            if( cur.prob * e->prob > prob[e->to]){
                prob[e->to] = cur.prob * e->prob;
                push(queue, e->to, prob[e->to]);
            }
        }
    }

    return prob[end_node];
}
