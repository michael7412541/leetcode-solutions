int compare(const void *a, const void *b){
    int *row1 = *(int **)(a);
    int *row2 = *(int **)(b);
    return row1[0] - row2[0];
}
int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
    qsort(reservedSeats, reservedSeatsSize, sizeof(reservedSeats), compare);
    int i = 0, seat[10], j = 0, count = 0,answer = 0, zone1, zone2, zone3, reserve = 0;
    while(count < reservedSeatsSize){
        memset(seat, 0, sizeof(seat));
        j = 0;
        zone1 = 0;
        zone2 = 0;
        zone3 = 0;
        
        i = reservedSeats[count][0];
        while(count < reservedSeatsSize && reservedSeats[count][0] == i){
            seat[--reservedSeats[count][1]]++;
            count++;
        }
        //for(int i = 0; i < 10; i++){
        //    if(seat[i] == 0) printf(" O ");
        //    else printf(" X ");
        //}
        //printf("\n");
        if(seat[1] == 0 && seat[2] == 0 && seat[3] == 0 && seat[4] == 0) zone1++;
        if(seat[5] == 0 && seat[6] == 0 && seat[7] == 0 && seat[8] == 0) zone2++;
        if((seat[3] == 0 && seat[4] == 0 && seat[5] == 0 && seat[6] == 0) && (zone1 == 0 && zone2 == 0)) zone3++;
        
        answer = answer + zone1 + zone2 + zone3;
        reserve++;
        //printf("%d, zone1 = %d, zone2 = %d, zone3 = %d\n", i, zone1, zone2, zone3);
    }
    answer += (n - reserve) * 2;
    return answer;
}
