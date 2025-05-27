int hash(char a) {
    return (int)a;
}
bool isIsomorphic(char* s, char* t) {
    if(s == NULL || t == NULL)
        return false;
    
    int i, len_s, len_t, idx_s,idx_t;
    int *map_s = (int*)malloc(sizeof(int)*128);
    memset(map_s, -1, 128*sizeof(int));
    int *map_t = (int*)malloc(sizeof(int)*128);
    memset(map_t, -1, 128*sizeof(int));
    len_s = strlen(s);
    len_t = strlen(t);
    if(len_s != len_t)
        return false;
    for(i = 0; i < len_s; i++)
    {
        idx_s = hash(s[i]);
        idx_t = hash(t[i]);
        
        if(map_s[idx_s] == -1) {
            map_s[idx_s] = idx_t;
        }
        else {
            if(map_s[idx_s] != idx_t)
                return false;
        }
        
        if(map_t[idx_t] == -1) {
            map_t[idx_t] = idx_s;
        }
        else {
            if(map_t[idx_t] != idx_s)
                return false;
        }
        
    }
    return true;
    
}
