/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//這題我根本不會 是gpt教我的


typedef struct {
    struct TreeNode **stack;
    int top;
    int capacity;
} BSTIterator;

void pushleft(BSTIterator *it, struct TreeNode *node){
    while(node != NULL){
        //當stack滿了就要擴充
        if(it->top + 1 >= it->capacity){
            int newcap = it->capacity * 2;
            struct TreeNode **newstack = realloc(it->stack, sizeof(struct TreeNode*));
            if(!newstack) return;
            it->stack = newstack;
            it->capacity = newcap;
        }
        it->stack[++it->top] = node;//放入一個node
        node = node->left;//node往左下移動
    }
}


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* it = (BSTIterator*)malloc(sizeof(BSTIterator));
    
    it->top = -1;
    it->capacity = 1000;
    it->stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*it->capacity);//(TreeNode**)
    
    //store tree info to stack
    pushleft(it, root);
    return it;
}


int bSTIteratorNext(BSTIterator* it) {
    struct TreeNode* node = it->stack[it->top--];
    
    int val = node->val;
    
    if(node->right != NULL)
        pushleft(it, node->right);
    
    return val;
}

bool bSTIteratorHasNext(BSTIterator* it) {
    return it->top >= 0;//stack有東西就表示還有下一個
}

void bSTIteratorFree(BSTIterator* it) {
    if(!it) return;
    free(it->stack);
    free(it);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
