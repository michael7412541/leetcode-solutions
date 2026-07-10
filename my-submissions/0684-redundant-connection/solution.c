/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int find(int x, int *parent){
    if(x == parent[x])
        return x;
    return find(parent[x], parent);
}


int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int *parent = malloc(sizeof(int) * (edgesSize+1));
    *returnSize = 2;
    for(int i = 0; i <= edgesSize; i++){
        parent[i] = i;
    }
    for(int i = 0; i < edgesSize; i++){
        int rootA = find(edges[i][0], parent);
        int rootB = find(edges[i][1], parent);

        if(rootA == rootB)
            return edges[i];
        else
            parent[rootB] = rootA;
    }
    return NULL;
}
