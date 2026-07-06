int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if(intervals == NULL || intervalsSize == 0)
        return 0;
    int include[intervalsSize];
    memset(include, 0, sizeof(include));
    int i = 0, j = 0, count = 0;
    
    for(i = 0; i < intervalsSize; i++){
        if(include[i] == 0)
            for(j = i + 1; j < intervalsSize; j++){
                if(intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]){
                    //i is included in j
                    include[i] = 1;
                }
                else if(intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]){
                    include[j] = 1;
                }
            }
        
    }
    for(i = 0; i < intervalsSize; i++)
        count += include[i];
    return intervalsSize - count;
}
