#define BUCKETSIZE 1000
typedef struct Node {
    int val;
    struct Node * next;
} Node;

typedef struct hashset {
    struct Node * Bucket[BUCKETSIZE];
} hashset;

int hash(int key) {
    return key % BUCKETSIZE;
}

int sqrt_sum(int n) {
    int temp = 0, sum = 0;
    while(n > 0) {
        temp = n % 10;
        sum += temp * temp;
        n = n/10;
    }
    return sum;
}
int check_add_hash(hashset *obj, int key) {
    int idx = hash(key);
    Node *curr = obj->Bucket[idx];
    while(curr != NULL) {
        if(curr->val == key) {
            if(key == 1)
                return 1;
            else
                return 2;
        }  
        curr = curr->next;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = key;
    newNode->next = obj->Bucket[idx];
    obj->Bucket[idx] = newNode;
    return 0;
}
bool isHappy(int n) {
    if(n <= 0)
        return false;
    struct hashset * set = (hashset*)malloc(sizeof(hashset));
    Node *curr = set->Bucket[0];
    int i = 0,sum = n, temp = 0;
    for(i = 0; i < BUCKETSIZE; i++) {
        set->Bucket[i] = NULL; 
    }
    while(sum > 0) {
        sum = sqrt_sum(sum);
        //printf("sum = %d\n", sum );
        temp = check_add_hash(set,sum);
        if(temp == 1)
            return 1;
        else if(temp == 2)
            return 0;
    
    }
    return 0;
    
}
