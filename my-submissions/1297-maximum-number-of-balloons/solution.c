int maxNumberOfBalloons(char* text) {
    int bucket[5] = {0}, min = INT_MAX;
    int size = strlen(text);
    if(size == 0)
        return 0;
    for(int i = 0; i < size; i++){
        if(text[i] == 'b')
            bucket[0]++;
        else if(text[i] == 'a')
            bucket[1]++;
        else if(text[i] == 'l')
            bucket[2]++;
        else if(text[i] == 'o')
            bucket[3]++;
        else if(text[i] == 'n')
            bucket[4]++;
    }

    bucket[3] /= 2;
    bucket[2] /= 2;
    for(int i = 0; i < 5; i++){
        if(bucket[i] < min)
            min = bucket[i];
    }
    return min;
}
