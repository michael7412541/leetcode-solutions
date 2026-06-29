bool helper(char *a, char *b, int size){    
    int size_a = strlen(a), flag = 0;
    for(int i = 0, j = 0; i < size; i++){
        j = 0;
        flag = 0;
        while(j < size_a && b[i+j] == a[j]){
            //printf("compare a[%d]:%c b[%d]:%c\n", j, a[j], i+j, b[i+j]);
            j++;
            flag = 1;
        }
        //printf("j=%d size_a=%d\n", j, size_a);
        if(j == size_a && flag == 1)
            return true;
    }
    return false;
}
int numOfStrings(char** patterns, int patternsSize, char* word) {
    int i, count = 0;
    int size = strlen(word);

    for(i = 0; i < patternsSize; i++){
        
        if(helper(patterns[i], word, size) == true) {
            printf("patterns[%d] = %s, %d\n", i, patterns[i], 1);
            count++;
        }
           
    }
    return count;
}
