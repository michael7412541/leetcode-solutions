bool check(int *hash1, int *hash2){
    for(int i = 0; i < 26; i++){
        if(hash1[i] != hash2[i])
            return false;
    }
    return true;
}

bool checkInclusion(char* s1, char* s2) {
    int hash1[26] = {0}, hash2[26] = {0};
    int left = 0, size1 = strlen(s1), size2 = strlen(s2);
    if(size2 < size1)
        return false;
    for(int i = 0; i < size1; i++){
        hash1[s1[i] - 'a']++;
        hash2[s2[i] - 'a']++;
    }
    for(int right = size1; right < size2; left++, right++){
        //calculate hash2
        
        //compare hash1 & hash2
        if(check(hash1, hash2))
            return true;
        //update window
        hash2[s2[left] - 'a']--;
        hash2[s2[right] - 'a']++;
       
    }

    return check(hash1, hash2);
}
