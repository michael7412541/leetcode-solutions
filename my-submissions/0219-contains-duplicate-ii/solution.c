#define BUCKETSIZE 10007

typedef struct Node {
    int val;
    int index;
    struct Node *next;
} Node;

typedef struct hashmap {
    struct Node *Bucket[BUCKETSIZE];
} hashmap;

int hash(int key) {
    return abs(key) % BUCKETSIZE;
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if(nums == NULL || numsSize == 0)
        return false;
    hashmap *map = (hashmap*)malloc(sizeof(hashmap));
    Node *curr;
    bool answer = false;
    int i = 0, idx;
    for(i = 0; i < BUCKETSIZE; i++)
    {
        map->Bucket[i] = NULL;
    }
    for(i = 0; i < numsSize; i++)
    {
        idx = hash(nums[i]);
        curr = map->Bucket[idx];
        while(curr != NULL)
        {
            //printf("nums[%d] = %d, curr->val = %d, curr->index = %d\n", i, nums[i],curr->val, curr->index);
            if(nums[i] == curr->val)
            {   
                if((i - curr->index) <= k)
                    return true;
                curr->index = i;
                break;
            }
            curr = curr->next;
        }
        if(curr== NULL) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->val = nums[i];
        newNode->index = i;
        newNode->next = map->Bucket[idx];
        map->Bucket[idx] = newNode;}
    }
    return false;
}
