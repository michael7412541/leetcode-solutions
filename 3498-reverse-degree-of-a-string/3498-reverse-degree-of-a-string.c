int reverseDegree(char* s) {
    int size = strlen(s);
    int temp, sum = 0;
    for(int i = 0; i < size; i++){
        temp = 'a' - s[i] + 26;
        sum += temp * (i + 1);
    }
    return sum;
}