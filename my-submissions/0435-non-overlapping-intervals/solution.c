int compare(void const *a, void const *b){
    int *intervalA = *(int**)a;
    int *intervalB = *(int**)b;

    return intervalA[1] - intervalB[1];
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    int answer = 0, lastEnd = INT_MIN, start = 0;
    for(int i = 0; i < intervalsSize; i++){
        start = intervals[i][0];
        if(start >= lastEnd){
            answer++;
            lastEnd = intervals[i][1];
        }
        
    }
    return intervalsSize - answer;
}
