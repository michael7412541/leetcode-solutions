char findTheDifference(char* s, char* t) {
    int result0 = 0, result1 = 0, i = 0;
    while(s[i] != '\0')
    {
        result0 = result0 ^ s[i];
        i++;
    }
    i = 0;
    while(t[i] != '\0')
    {
        result1 = result1 ^ t[i];
        i++;
    }
    return result0 ^ result1;

}
