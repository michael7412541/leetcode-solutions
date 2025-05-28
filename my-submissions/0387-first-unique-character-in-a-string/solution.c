int hash(char s){
    return s - 'a';
}
int firstUniqChar(char* s) {
    int *hashmap = (int*)malloc(sizeof(int)*26);
    memset(hashmap, 0, sizeof(int)*26);
    int i = 0, idx, answer = -1;
    for(i = strlen(s) - 1; i >= 0; i--) {
        idx = hash(s[i]);
        hashmap[idx]++;
    }
    for(i = strlen(s) - 1; i >= 0; i--) {
        idx = hash(s[i]);
        if(hashmap[idx] == 1)
            answer = i;
    }
    
    return answer;
}
