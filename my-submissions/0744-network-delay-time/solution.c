typedef struct{
    int node;
    int dist;
} HeapNode;

typedef struct{
    HeapNode *data;
    int size;
    int capacity;
} MinHeap;

typedef struct Edge{
    int to;
    int weight;
    struct Edge *next;
} Edge;

void swap(HeapNode *a, HeapNode *b){
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(MinHeap *heap, int index){
    int small = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if(left < heap->size && small < heap->data[left].dist)
        small = left;
    if(right < heap->size && small < heap->data[right].dist)
        small = right;
    
    if(small != index){
        swap(&heap->data[index], &heap->data[small]);
        heapifyDown(heap, small);
    }
}

void heapifyUp(MinHeap *heap, int index){
    if(index == 0) return;

    int parent = (index - 1)/2;
    if(heap->data[parent].dist > heap->data[index].dist){
        swap(&heap->data[parent], &heap->data[index]);
        heapifyUp(heap, parent);
    }
}
void push(MinHeap *heap, int node, int dist){
    heap->data[heap->size].node = node;
    heap->data[heap->size].dist = dist;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}
HeapNode pop(MinHeap *heap){
    HeapNode result = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return result;
}





int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){
    MinHeap *heap = malloc(sizeof(MinHeap));
    heap->data = malloc(sizeof(HeapNode) * 1000);
    heap->size = 0;
    heap->capacity = 1000;

    Edge **graph = malloc(sizeof(Edge*) * (n+1));

    int dist[n+1];
    for(int i = 1; i <= n; i++){
        dist[i] = INT_MAX;
        graph[i] = NULL;
    }
    for(int i = 0; i < timesSize; i++){
        int from = times[i][0];
        int to = times[i][1];
        int weight = times[i][2];
        Edge *new = malloc(sizeof(Edge));
        new->to = to;
        new->weight = weight;
        new->next = graph[from];
        graph[from] = new;
    }
    dist[k] = 0;
    push(heap, k, 0);
    while(heap->size != 0){
        HeapNode cur = pop(heap);
        int u = cur.node;

        if(cur.dist > dist[u])
            continue;

        for(Edge *e = graph[u]; e; e = e->next){
            int newdist = dist[u] + e->weight;
            if(newdist < dist[e->to]){
                dist[e->to] = newdist;
                push(heap, e->to, newdist);
            }
        }
    }

    free(heap->data);
    free(heap);

    int answer = -1;
    for(int i = 1; i <= n; i++){
        if(dist[i] == INT_MAX)
            return -1;

        if(dist[i] > answer)
            answer = dist[i];
    }


    
    return answer;
}
