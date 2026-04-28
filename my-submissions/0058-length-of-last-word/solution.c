int lengthOfLastWord(char* s) {
    int size = strlen(s), count = 0;
    for(int i = size - 1; i >= 0; i--){
        if(s[i] != ' ')
            count++;
        if(count != 0 && s[i] == ' ')
            break;
    }

    return count;
}
