typedef struct {
    int count;
    int key;
    UT_hash_handle hh;
} HashNode;
int subarraySum(int* nums, int numsSize, int k) {
    HashNode *map = NULL;
    HashNode *node = malloc(sizeof(HashNode)), *node1, *node2;
    node->count = 1;
    node->key = 0;
    HASH_ADD_INT(map, key, node);
    int current_sum = 0, target = 0, answer = 0;
    for(int i = 0; i < numsSize; i++){
        current_sum += nums[i];
        target = current_sum - k;

        HASH_FIND_INT(map, &target, node1);
        if(node1 != NULL){
            answer += node1->count;
        }

        HASH_FIND_INT(map, &current_sum, node2);
        if(node2 != NULL){
            node2->count++;
        }
        else{
            node2 = malloc(sizeof(HashNode));
            node2->count = 1;
            node2->key = current_sum;
            HASH_ADD_INT(map, key, node2);

        }
        
    }
    return answer;
}
