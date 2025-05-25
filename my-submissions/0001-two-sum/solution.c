/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define BUCKETSIZE 1000

typedef struct Node {
    int val;
    int index;
    struct Node *next;
} Node;

int hash(int key) {
    return abs(key) % BUCKETSIZE;
}

typedef struct hashmap{
    struct Node *Bucket[BUCKETSIZE];
} hashmap;

void add_map(hashmap *map, int key, int index) {
    int idx = hash(key);

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->index = index;
    newNode->val = key;
    newNode->next = map->Bucket[idx];
    map->Bucket[idx] = newNode;
}

int check_map(hashmap *map, int key) {
    int idx = hash(key);
    Node *curr = map->Bucket[idx];
    while(curr != NULL) {
        if(curr->val == key) {
            return curr->index;
        }
        curr= curr->next;
    }
    return -1;
}

void freemap(hashmap *map) {
    Node *curr, *prev = NULL;
    int i = 0;
    for(i = 0; i < BUCKETSIZE; i++) {
        curr = map->Bucket[i];
        while(curr != NULL) {
            prev = curr;
            curr = curr->next;
            free(prev);
        }
        
    }
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    if(nums == NULL || numsSize == 0)
        return NULL;
    int i = 0, temp;
    int* answer = (int*)malloc(sizeof(int)*2);
    hashmap *map = (hashmap*)malloc(sizeof(hashmap));
    for(i = 0; i < BUCKETSIZE; i++) {
        map->Bucket[i] = NULL;
    }
    for(i = 0; i < numsSize; i++) {
        temp = check_map(map, target - nums[i]); 
        if(temp >= 0) {
            freemap(map);
            answer[0] = i;
            answer[1] = temp;
            *returnSize = 2;
            return answer;
        }
        add_map(map, nums[i], i);
        //printf("temp = %d, add nums[%d] = %d \n", temp, i, nums[i]);
    }
    freemap(map);
    return NULL;
}
