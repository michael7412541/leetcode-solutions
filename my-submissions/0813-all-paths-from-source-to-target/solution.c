/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int node, int end, int *path, int pathsize, int **graph, int graphSize, int *graphColSize, int *returnSize, int **returnColumnSizes, int **answer){
    //printf("node=%d end=%d\n", node, end);
    path[pathsize++] = node;
    //printf("returnSize=%d\n", *returnSize);
    //printf("graphSize=%d\n", graphSize);
    if(node == end){
        answer[(*returnSize)] = malloc(sizeof(int) * 10000);
        for(int k = 0; k < pathsize; k++){
            answer[(*returnSize)][k] = path[k];
        }
        
        (*returnColumnSizes)[(*returnSize)] = pathsize;
        (*returnSize)++;
        return;
    }
    

    for(int i = 0; i < graphColSize[node]; i++){
        dfs(graph[node][i], end, path, pathsize, graph, graphSize, graphColSize, returnSize, returnColumnSizes, answer);
    }
}


int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes) {
    int *path = malloc(sizeof(int) * 10000);
    int **answer = malloc(sizeof(int*) * 10000);
    *returnColumnSizes = malloc(sizeof(int) * 10000);
    (*returnSize) = 0;

    dfs(0, graphSize - 1, path, 0, graph, graphSize, graphColSize, returnSize, returnColumnSizes, answer);

    return answer;
}
