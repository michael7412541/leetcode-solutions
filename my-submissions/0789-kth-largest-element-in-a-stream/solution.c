


typedef struct Node{
    int val;
    int count;
    int LeftSize;
    int RightSize;
    struct Node *left, *right;
} Node;


typedef struct {
    Node *root;
    int k;
} KthLargest;

Node *newNode(int val){
    Node *n = malloc(sizeof(Node));
    n->val = val;
    n->count = 1;
    n->LeftSize = 0;
    n->RightSize = 0;
    n->left = n->right = NULL;
    return n;
}

Node *insert(Node *root, int val){
    if(!root) return newNode(val);
    
    if(val == root->val){
        root->count++;
    }
    else if(val < root->val){
        root->left = insert(root->left, val);
        root->LeftSize++;
    }
    else{
        root->right = insert(root->right, val);
        root->RightSize++;
    }
    return root;
}


KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = malloc(sizeof(KthLargest));
    obj->k = k;
    obj->root= NULL;
    for(int i = 0; i < numsSize; i++){
        obj->root = insert(obj->root, nums[i]);
    }
    return obj;
    
}

int find(Node * root, int k){
    while(root){
        int right = root->RightSize;
        int self = root->count;
        
        if(right >= k){
            root = root->right;
        }
        else if(right + self >= k) {
            return root->val;
        }
        else{
            k -= (right + self);
            root = root->left;
        }
    }
    return -1;
}

int kthLargestAdd(KthLargest* obj, int val) {
    obj->root = insert(obj->root, val);
    return find(obj->root, obj->k);
        
}

void freeTree(Node *root){
    if(!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void kthLargestFree(KthLargest* obj) {
    freeTree(obj->root);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/
