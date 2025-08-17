void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(char *s, int size, int p) {
    if(p >= size/2)
        return;
    else {
        swap(&s[p], &s[size - p - 1]);
        reverse(s, size, p + 1);
    }
}
void reverseString(char* s, int sSize) {
    
    reverse(s, sSize, 0);
}


