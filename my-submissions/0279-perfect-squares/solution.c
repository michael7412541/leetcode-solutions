int numSquares(int n) {//這題我根本寫不出來
    if(n <= 0)
        return 0;
    
    int root = (int)sqrt(n);
    int square[root];
    for(int i = 1; i <= root; i++) {
        square[i-1] = i * i;
    }
    
    int *queue = (int*)malloc(sizeof(int)*(n + 1));
    bool *visited = (bool*)calloc(n + 1, sizeof(bool));
    
    int head = 0, tail = 0;
    queue[tail++] = n;
    visited[n] = true;
    int steps = 0;
    
    while(head < tail) {
        steps++;
        int size = tail - head;
        for(int i = 0; i < size; i++) {
            int curr = queue[head++];
            
            for(int j = 0; j < root; j++) {
                int next = curr - square[j];
                if(next < 0) break;
                
                if(next == 0) {
                    free(queue);
                    free(visited);
                    return steps;
                }
                if(!visited[next]) {
                    visited[next] = true;
                    queue[tail++] = next;
                }
            }
        }
    }
    free(queue);
    free(visited);
    return steps;
}
