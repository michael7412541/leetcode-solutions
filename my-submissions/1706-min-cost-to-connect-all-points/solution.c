int find(int x, int *parent){
    if(x != parent[x])
        parent[x] = find(parent[x], parent);
    return parent[x];
}

int compare(void const *a, void const *b){
    int *edgeA = *(int**)a;
    int *edgeB = *(int**)b;

    return edgeA[2] - edgeB[2];
}
int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int num = pointsSize * (pointsSize - 1)/2;
    int **edge = malloc(sizeof(int*) * num), count = 0, answer = 0;
    int *parent = malloc(sizeof(int) * pointsSize);

    for(int i = 0; i < pointsSize; i++){
        parent[i] = i;
        
        for(int j = i + 1; j < pointsSize; j++){
            edge[count] = malloc(sizeof(int) * 3);
            edge[count][0] = i;
            edge[count][1] = j;
            edge[count][2] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) ;
            count++;
        }
    }
    
    qsort(edge, count, sizeof(int*), compare);

    for(int i = 0; i < count; i++){
        int rootA = find(edge[i][0], parent);
        int rootB = find(edge[i][1], parent);
        if(rootA != rootB){
            parent[rootB] = rootA;
            answer += edge[i][2];
        }
    }

    return answer;
}
