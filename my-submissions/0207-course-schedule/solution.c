bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int indegree[numCourses];
    int graph[numCourses][numCourses];
    int degree[numCourses];
    int count = 0;
    memset(graph, -1, sizeof(graph));
    memset(degree, 0, sizeof(degree));
    memset(indegree, 0, sizeof(indegree));

    for(int i = 0; i < prerequisitesSize; i++){
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];
        indegree[course]++;
        graph[pre][degree[pre]++] = course; 
    }
    int queue[numCourses];
    int front = -1, rear = -1, cur = 0, finish = 0;
    for(int i = 0; i < numCourses; i++){
        if(indegree[i] == 0)
            queue[++rear] = i;
    }
    while(front < rear){
        cur = queue[++front];
        count++;
        
        for(int i = 0; i < degree[cur]; i++){
            int idx = graph[cur][i];
            indegree[idx]--;
            if(indegree[idx] == 0)
                queue[++rear] = idx;
        }
    }
    return count == numCourses;
}
