bool checkStrings(char* s1, char* s2) {
    int hash_odd1[26] = {0}, hash_even1[26] = {0};
    int hash_odd2[26] = {0}, hash_even2[26] = {0};
    int size1 = strlen(s1), size2 = strlen(s2);
    if(size1 != size2)
        return false;
    
    for(int i = 0; i < size1; i++){
        if(i % 2 != 0){
            hash_odd1[s1[i] - 'a']++;
            hash_odd2[s2[i] - 'a']++;
        }     
        else{
            hash_even1[s1[i] - 'a']++;
            hash_even2[s2[i] - 'a']++;
        }  
    }
    for(int i = 0; i < 26; i++){
        if(hash_odd1[i] != hash_odd2[i] || hash_even1[i] != hash_even2[i]) 
            return false;
    }
    return true;
    
}
