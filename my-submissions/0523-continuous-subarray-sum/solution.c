typedef struct {
    int key;
    int index;
    UT_hash_handle hh;
} HashNode;
bool checkSubarraySum(int* nums, int numsSize, int k) {
    
    HashNode *map = NULL;
    HashNode *node = malloc(sizeof(HashNode));
    node->key = 0;
    node->index = -1;
    HASH_ADD_INT(map, key, node);
    int current_sum = 0, target = 0;
    for(int i = 0; i < numsSize; i++){
        current_sum += nums[i];
        target = current_sum % k;
        HASH_FIND_INT(map, &target, node);
        if(node != NULL){
            if(i - node->index >= 2)
                return true;
            
        }
        else{
            node = malloc(sizeof(HashNode));
            node->key = target;
            node->index = i;
            HASH_ADD_INT(map, key, node);
        }
    }

    return false;
    
}
