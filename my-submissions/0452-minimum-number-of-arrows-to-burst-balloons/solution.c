int compare(const void *a, const void *b){
    int *intervalA = *(int**)a;
    int *intervalB = *(int**)b;
    if(intervalA[1] > intervalB[1]) return 1;
    if(intervalA[1] < intervalB[1]) return -1;
 return 0;
}
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if(pointsSize == 1)
        return 1;
    int lastEnd, count = 1;
    qsort(points, pointsSize, sizeof(int*), compare);
    lastEnd = points[0][1];
    for(int i = 1; i < pointsSize; i++){
        if(lastEnd < points[i][0]){
            count++;
            lastEnd = points[i][1];
        }
    }
    return count;
}
