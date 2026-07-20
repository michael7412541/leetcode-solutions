int find(int x, int *parent){
    if(x == parent[x])
        return x;
    else
        return find(parent[x], parent);
}
int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    if(connectionsSize < n - 1)
        return -1;
    int *parent = malloc(sizeof(int) * n);
    int hash[n], count = 0;
    memset(hash, 0, sizeof(hash));
    for(int i = 0; i < n; i++)
        parent[i] = i;

    for(int i = 0; i < connectionsSize; i++){
        int rootA = find(connections[i][0], parent);
        int rootB = find(connections[i][1], parent);
        if(rootA != rootB)
            parent[rootB] = rootA;
    }

    for(int i = 0; i < n; i++){
        hash[find(i, parent)]++;
    }
    for(int i = 0; i < n; i++){
        
        if(hash[i] > 0){
            ///printf("%d ", i);
            count++;
        }
            
    }
    free(parent);
    return count - 1;
}
