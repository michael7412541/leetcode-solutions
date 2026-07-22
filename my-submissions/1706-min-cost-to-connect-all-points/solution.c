int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int dist[pointsSize];
    int visited[pointsSize];
    memset(visited, 0, sizeof(visited));
    int min = INT_MAX, min_idx = 0, x = points[0][0], y = points[0][1];
    dist[0] = 0;
    visited[0] = 1;
    for(int i = 1; i < pointsSize; i++){
        dist[i] = abs(points[i][0] - x) + abs(points[i][1] - y);
    }
    for(int i = 1; i < pointsSize; i++){
        min = INT_MAX;
        for(int j = 1; j < pointsSize; j++){
            if(visited[j] == 1)
                continue;
            
            if(dist[j] < min){
                min = dist[j];
                min_idx = j;
            }
        }

        visited[min_idx] = 1;
        for(int k = 1; k < pointsSize; k++){
            if(visited[k] == 1)
                continue;
            int cost = abs(points[k][0] - points[min_idx][0]) + abs(points[k][1] - points[min_idx][1]);
            dist[k] = cost > dist[k] ? dist[k] : cost;
        }
    }

    int answer = 0;
    for(int i = 0; i < pointsSize; i++){
        answer += dist[i];
    }

    return answer;

}
