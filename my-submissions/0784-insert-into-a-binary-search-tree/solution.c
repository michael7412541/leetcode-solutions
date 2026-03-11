/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if(root == NULL){
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = NULL;
        node->right = NULL;//很容易忘記!!!
        return node;
    }    

    int dir = 0;
    struct TreeNode* head = root;
    struct TreeNode* prev = NULL;
    while(head != NULL){
        prev = head;
        if(val > head->val){
            head = head->right;
            dir = 0;
        }
        else{
            head = head->left;
            dir = 1;
        }
        
    }
    
    struct TreeNode* node =(struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    
    if(dir == 0){
        prev->right = node;
    }
    else{
        prev->left = node;
    }

    return root;
}*/
void helper(struct TreeNode* root, int val){ 
    if(root->val > val){
        if(root->left != NULL)
            helper(root->left, val);
        else{
            struct TreeNode *node = malloc(sizeof(struct TreeNode));
            node->val = val;
            node->left = NULL;
            node->right = NULL;
            root->left = node;
        }
    }
    else{
        if(root->right != NULL)
            helper(root->right, val);
        else{
            struct TreeNode *node = malloc(sizeof(struct TreeNode));
            node->val = val;
            node->left = NULL;
            node->right = NULL;
            root->right = node;
        }
    }
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if(root == NULL){
        struct TreeNode *node = malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    
    helper(root, val);
    
    
    return root;
}
