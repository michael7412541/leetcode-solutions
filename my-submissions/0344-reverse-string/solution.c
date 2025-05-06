void swap(char *a, char *b) ;
void reverseString(char* s, int sSize) {
    
    int i = 0;
    for(i = 0; i < sSize/2; i++)
    {
        swap(&s[i], &s[sSize-1-i]);
    }
}

void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
