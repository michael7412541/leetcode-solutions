/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_WORD_LEN 100
#define MAX_GROUPS 10000

typedef struct {
    char *key;
    char **words;
    int size;
    int capacity;
    UT_hash_handle hh;
} AnagramGroup;

int cmp_char(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

char *getSortedKey(const char *word) {
    char *key = strdup(word);
    qsort(key, strlen(key), sizeof(char), cmp_char);
    return key;
}

void addtoGroup(AnagramGroup *group, const char *word) {
    if(group->size >= group->capacity) {
        group->capacity *= 2;
        group->words = realloc(group->words, group->capacity * sizeof(char*));
    }
    group->words[group->size++] = strdup(word);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    //*returnSize表示有幾組
    //**returnColumnSizes表示每組有多少個
   AnagramGroup *groups = NULL;
    for(int i = 0; i < strsSize; i++)
    {
        char *key = getSortedKey(strs[i]);
        AnagramGroup * found = NULL;
        HASH_FIND_STR(groups, key, found);
        
        if(!found) {
            found = malloc(sizeof(AnagramGroup));
            found->key = key;
            found->size = 0;
            found->capacity = 2;
            found->words = malloc(found->capacity * sizeof(char*));
            HASH_ADD_KEYPTR(hh, groups, found->key, strlen(found->key), found);
        }
        else {
            free(key);
        }
        
        addtoGroup(found, strs[i]);
    }
    
    int groupCount = HASH_COUNT(groups);
    *returnSize = groupCount;
    *returnColumnSizes = malloc(groupCount * sizeof(int));
    char *** result = malloc(groupCount * sizeof(char**));
    
    int idx = 0;
    AnagramGroup *current, *tmp;
    HASH_ITER(hh, groups, current, tmp) {
        result[idx] = current->words;
        (*returnColumnSizes)[idx] = current->size;
        idx++;
        
        HASH_DEL(groups, current);
        free(current->key);
        free(current);
    }
    
    return result;
}
