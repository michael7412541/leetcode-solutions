/*int hash(char c)
{
    return (int)c - 'A';
}
int numJewelsInStones(char* jewels, char* stones) {
    if(jewels == NULL || stones == NULL)
        return 0;
    
    int i = 0, count = 0, map[70] = {0};
    
    for(i = 0; i < strlen(jewels); i++)
    {
        int idx = hash(jewels[i]);
        map[idx]++;
    }
    for(i = 0; i < strlen(stones); i++)
    {
        int idx = hash(stones[i]);
        if(map[idx] != 0)
            count++;
    }
    
    return count;
}*/
//#include "uthash.h"
typedef struct {
    int key;
    int count;
    UT_hash_handle hh;
} charcnt;

int numJewelsInStones(char* jewels, char* stones) {
    int i = 0, count = 0;
    charcnt *hashtable = NULL;
    for(i = 0; i < strlen(jewels); i++)
    {
        charcnt *entry;
        entry = (charcnt*)malloc(sizeof(charcnt));
        entry->count = 1;
        entry->key = (int)jewels[i];
        HASH_ADD_INT(hashtable, key, entry);
    }
    for(i = 0; i < strlen(stones); i++)
    {
        charcnt *tmp;
        int key = (int)stones[i];
        HASH_FIND_INT(hashtable, &key, tmp);
        if(tmp)
            count++;
    }
    return count;
}
