typedef struct {
    int key;
    int count;
    UT_hash_handle hh;
} HashNode;
int subarraysDivByK(int* nums, int numsSize, int k) {
    int target, current_sum = 0, answer = 0;
    HashNode *map = NULL, *node;
    node = malloc(sizeof(HashNode));
    node->key = 0;
    node->count = 1;
    HASH_ADD_INT(map, key, node);
    for(int i = 0; i < numsSize; i++){
        current_sum += nums[i];
        target = (current_sum % k + k) % k; //key point
        HASH_FIND_INT(map, &target, node);
        if(node != NULL){
            answer += node->count;
            node->count++;
        }
        else{
            node = malloc(sizeof(HashNode));
            node->key = target;
            node->count = 1;
            HASH_ADD_INT(map, key, node);
        }

    }
    return answer;
}
