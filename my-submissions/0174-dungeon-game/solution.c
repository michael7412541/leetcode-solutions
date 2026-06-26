int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    int record[200][200], health[200][200], h, v, temp;
    
    if(dungeonSize == 0) return -1;
    for(int i = dungeonSize - 1; i >= 0; i--){
        for(int j = dungeonColSize[i] - 1; j >= 0; j--){
           if(i == dungeonSize - 1 && j == dungeonColSize[i] - 1){
                record[i][j] = -dungeon[dungeonSize - 1][dungeonColSize[0] - 1];
           }
           else{
            h = i + 1 < dungeonSize ? record[i + 1][j] : INT_MAX;
            v = j + 1 < dungeonColSize[0] ? record[i][j + 1] : INT_MAX;
            record[i][j] = (h > v ? v : h) - dungeon[i][j];
            
           }

           if(record[i][j] < 0)
                record[i][j] = 0;
           
        }
    }

    /*for(int i = 0; i < dungeonSize; i++){
        for(int j = 0; j < dungeonColSize[i]; j++)
            printf("%d ", record[i][j]);
        
        printf("\n");
    }*/
    
    return record[0][0] + 1;
}
