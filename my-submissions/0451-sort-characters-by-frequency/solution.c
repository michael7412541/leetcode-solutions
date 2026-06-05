struct BucketNode {
    char val;
    struct BucketNode *next;
};
char* frequencySort(char* s) {
    int count = 0, freq, size = strlen(s), hash[128] = {0}, max = 0;
    char *answer = malloc(sizeof(char)*(size+1));
    struct BucketNode *bucket[size + 1], *temp = NULL;
    for(int i = 0; i < size + 1; i++){
        if(i < size)
            hash[s[i]]++;
        bucket[i] = NULL;
    }
    for(int i = 0; i < 128; i++){
        freq = hash[i];
        if(hash[i] > 0){
            if(freq > max)
                max = freq;
            if(bucket[freq] == NULL){
                bucket[freq] = malloc(sizeof(struct BucketNode));
                bucket[freq]->val = i;
                bucket[freq]->next = NULL;
            }
            else{
                struct BucketNode *new = malloc(sizeof(struct BucketNode));
                new->val = i;
                new->next = bucket[freq];
                bucket[freq] = new;
            }
        }
    }
    for(int i = max; i >= 0; i--){
        temp = bucket[i];
        while(temp != NULL){
            for(int j = 0; j < i; j++){
                answer[count++] = temp->val;
            }
            temp = temp->next;
        }
    }
    answer[size] = '\0';
    return answer;
}
