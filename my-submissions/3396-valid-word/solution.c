bool isValid(char* word) {
    if(strlen(word) < 3)
        return false;
    int vowel = 0, con = 0, others = 0, digits = 0;
    for(int i = 0; i < strlen(word); i++){
        if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' 
        || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U')
            vowel++;
        else if(word[i] >= '0' && word[i] <= '9')
            digits++;
        else if(word[i] >= 'a' && word[i] <= 'z')
            con++;
        else if(word[i] >= 'A' && word[i] <= 'Z')
            con++;
        else
            others++;
    }
    
    if(con == 0 || vowel == 0 || others > 0)
        return false;

    return true;
}
