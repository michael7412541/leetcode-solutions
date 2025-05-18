#define BUCKETSIZE 1000
typedef struct Node{
    int val;
    struct Node* next;
} Node;


typedef struct MyHashSet{
    struct Node* Bucket[BUCKETSIZE];
} MyHashSet;

int hash(int key) {
    return key % BUCKETSIZE;
}

MyHashSet* myHashSetCreate() {
    MyHashSet* set = (MyHashSet*)malloc(sizeof(MyHashSet));//給記憶體空間
    int i = 0;
    for(i = 0; i < BUCKETSIZE; i++)//初始化 把linked list陣列都設到NULL
    {
        set->Bucket[i] = NULL;//都先設NULL，有需要再給值
    }
    return set;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int idx = hash(key);
   // Node* curr = (Node*)malloc(sizeof(Node));
    Node *curr = obj->Bucket[idx];
    while(curr != NULL)
    {
        if(curr->val == key)
            return;
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->val = key;
    newNode->next = obj->Bucket[idx];
    obj->Bucket[idx] = newNode;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    //Node* curr = (Node*)malloc(sizeof(Node)); 不需要malloc 會造成memory leak
    //Node* prev = (Node*)malloc(sizeof(Node));
    Node *curr, *prev = NULL;
    int idx = hash(key);
    curr = obj->Bucket[idx];
    while(curr != NULL)
    {
        if(curr->val == key)
        {
            if(prev == NULL)
            {
                obj->Bucket[idx] = curr->next;
                
            }
            else
            {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }    
        prev = curr;
        curr = curr->next;
    }
    
}

bool myHashSetContains(MyHashSet* obj, int key) {
    
    int idx = hash(key);
    Node* curr = obj->Bucket[idx];
    while(curr != NULL)
    {
        if(curr->val == key)
            return true;
        curr = curr->next;
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    Node* curr, *prev = NULL;
    int i = 0;
    for(i = 0; i < BUCKETSIZE; i++)
    {
        curr = obj->Bucket[i];
        while(curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            free(prev);
        }
    }
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
