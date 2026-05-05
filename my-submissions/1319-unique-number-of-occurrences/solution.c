typedef struct {
    int key;
    int count;
    UT_hash_handle hh;
} HashNode;
bool uniqueOccurrences(int* arr, int arrSize) {
    HashNode *map = NULL;
    HashNode *count = NULL;

    for(int i = 0; i < arrSize; i++){
        HashNode *node;

        HASH_FIND_INT(map, &arr[i], node);
        if(node != NULL){
            node->count++;
            
        }
        else{
            node = malloc(sizeof(HashNode));
            node->count = 1;
            node->key = arr[i];
            HASH_ADD_INT(map, key, node);
        }

    }
    
    for(int i = 0; i < arrSize; i++){
        HashNode *node;
        HashNode *node_c;
        HASH_FIND_INT(map, &arr[i], node);
        if(node != NULL){
            HASH_FIND_INT(count, &node->count, node_c);
            if(node_c != NULL){
                return false;
            }
            else{
                node_c = malloc(sizeof(HashNode));
                node_c->key = node->count;
                node_c->count = 1;
                HASH_ADD_INT(count, key, node_c);
                HASH_DEL(map, node);
            }
        }
    }
    return true;
}
