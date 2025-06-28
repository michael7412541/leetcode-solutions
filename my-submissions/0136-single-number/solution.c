/*#define BUCKETSIZE 1000
typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct hashset {
    struct Node *Bucket[BUCKETSIZE];
} hashset;

int hash(int key) {
    return abs(key) % BUCKETSIZE;
}

void hashadd(hashset *obj, int key) {
    int idx = hash(key); 
    struct Node* curr = obj->Bucket[idx], *prev = NULL;
    while(curr != NULL) {
        if(curr->val == key) {
            if(prev == NULL)
                obj->Bucket[idx] = curr->next;
            else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    struct Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = key;
    newNode->next = obj->Bucket[idx];
    obj->Bucket[idx] = newNode;
}

int findsingle(hashset *obj) {
    int i = 0, answer;
    struct Node* curr;
    for(i = 0; i < BUCKETSIZE; i++) {
        
        curr = obj->Bucket[i];
        if(curr != NULL) {
            answer = curr->val; 
            free(curr);
            return answer;
        }
            
    }
    return 0;
}
void hashsetinit(hashset *obj) {
    int i = 0;
    for(i = 0; i < BUCKETSIZE; i++) {
        obj->Bucket[i] = NULL;
    }
}
int singleNumber(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)
        return -1;
    hashset *set = (hashset*)malloc(sizeof(hashset));
    hashsetinit(set);
    int i = 0, answer = 0;
    for(i = 0; i < numsSize; i++) {
        hashadd(set, nums[i]);
    }
    answer = findsingle(set);
    return answer;
    
}*/

int singleNumber(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)
        return 0;
    int i = 0, answer = nums[0];
    for(i = 1; i < numsSize; i++)
    {
        answer = answer ^ nums[i];
    }
    return answer;
    
}
