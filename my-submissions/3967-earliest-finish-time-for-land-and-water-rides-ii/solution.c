int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    int landend[landStartTimeSize], waterend[waterStartTimeSize];
    int minL = INT_MAX, minR = INT_MAX, answer = INT_MAX, temp;
    for(int i = 0; i  < landStartTimeSize; i++){
        landend[i] =  landStartTime[i] + landDuration[i];
        if(landend[i] < minL)
            minL = landend[i];
    }
    for(int i = 0; i  < waterStartTimeSize; i++){
        waterend[i] =  waterStartTime[i] + waterDuration[i];
        if(waterend[i] < minR)
            minR = waterend[i];
    }
    printf("%d %d", minL, minR);
    for(int i = 0; i < landStartTimeSize; i++){
        if(landStartTime[i] >= minR){
            temp = landend[i];
        }
        else{
            temp = minR + landDuration[i];
        }
        if(temp < answer)
            answer = temp;
    }
    for(int i = 0; i < waterStartTimeSize; i++){
        if(waterStartTime[i] >= minL){
            temp = waterend[i];
        }
        else{
            temp = minL + waterDuration[i];
        }
        if(temp < answer)
            answer = temp;
    }
    return answer;

}
