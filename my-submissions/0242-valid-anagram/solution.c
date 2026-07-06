bool isAnagram(char* s, char* t) {
    int hash[26];
    memset(hash, 0, sizeof(hash));
    int sizes = strlen(s), sizet = strlen(t);
    if(sizes != sizet)
        return false;
    
    for(int i = 0; i < sizes; i++){
        hash[s[i] - 'a']++;
        hash[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(hash[i] != 0)
            return false;
    }
    return true;
}
