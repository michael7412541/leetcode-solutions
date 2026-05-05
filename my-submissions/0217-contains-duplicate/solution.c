//#include "uthash.h"

typedef struct {
    int key;
    int count;
    UT_hash_handle hh;
} HashNode;
bool containsDuplicate(int* nums, int numsSize) {
    HashNode *map = NULL;
    for(int i = 0; i < numsSize; i++){
        HashNode *node;

        HASH_FIND_INT(map, &nums[i], node);
        if(node != NULL){
            return true;
        }
        else{
            node = malloc(sizeof(HashNode));
            node->key = nums[i];
            node->count = 1;
            HASH_ADD_INT(map, key, node);
        }
    }
    return false;
}
