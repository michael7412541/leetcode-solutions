#define BUCKETSIZE 1000
typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct hashset {
    struct Node* bucket[BUCKETSIZE];
} hashset;

int hash(int key) {
    return abs(key) % BUCKETSIZE;
}

bool hashsetadd(hashset *obj, int key) {
    Node *curr = obj->bucket[hash(key)];
    while(curr != NULL) {
        if(curr->val == key)
            return true;
        curr = curr->next;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = key;
    newNode->next = obj->bucket[hash(key)];
    obj->bucket[hash(key)] = newNode;
    return false;
}

void hashsetinit(hashset *obj) {
    int i = 0;
    for(i = 0; i < BUCKETSIZE; i++) {
        obj->bucket[i] = NULL;
    }
}

bool containsDuplicate(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)
        return false;
    hashset* set = (hashset*)malloc(sizeof(hashset));
    hashsetinit(set);
    int i = 0;
    bool temp = false;
    for(i = 0; i < numsSize; i++) {
        temp = hashsetadd(set, nums[i]);
        if(temp == true)
            return true;
    }
    return false;
}
