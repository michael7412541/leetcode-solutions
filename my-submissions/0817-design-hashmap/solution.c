#define BUCKETSIZE 1000
typedef struct Node{
    int key;
    int val;
    struct Node* next;
} Node;

typedef struct {
    struct Node* Bucket[BUCKETSIZE];
} MyHashMap;

int hash(int key)
{
    return key % BUCKETSIZE;
}
MyHashMap* myHashMapCreate() {
    MyHashMap * map = (MyHashMap*)malloc(sizeof(MyHashMap));
    int i = 0;
    for(i = 0; i < BUCKETSIZE; i++)
    {
        map->Bucket[i] = NULL;
    }
    return map;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int idx = hash(key);
    Node *curr = obj->Bucket[idx];
    while (curr) {
        if (curr->key == key) {
            curr->val = value;  // 如果 key 已存在，就更新 value
        return;
        }
        curr = curr->next;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = obj->Bucket[idx];
    newNode->key = key;
    obj->Bucket[idx] = newNode;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int idx = hash(key);
        
    Node * curr = obj->Bucket[idx];
    while(curr != NULL){
        if(curr->key == key){
            return curr->val;
        }
        curr = curr->next;
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int idx = hash(key);
    Node *curr, *prev = NULL;
    curr = obj->Bucket[idx];
    while(curr != NULL){
        if(curr->key == key)
        {
            if(prev == NULL)
                obj->Bucket[idx] = curr->next;
            else
                prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    int i = 0;
    Node *curr, *prev = NULL;
    for(i = 0; i < BUCKETSIZE; i++)
    {
        curr = obj->Bucket[i];
        while(curr != NULL){
            prev = curr;
            curr = curr->next;
            free(prev);
        }
    }
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
