/**
 * Definition for a binary tree node.
  * struct TreeNode {
   *     int val;
    *     struct TreeNode *left;
     *     struct TreeNode *right;
      * };
       */

struct TreeNode *helper(struct TreeNode *root){
    if(root == NULL)
        return NULL;
    struct TreeNode *L = root->left;
    struct TreeNode *R = root->right;

    struct TreeNode *L_tail = helper(L);
    struct TreeNode *R_tail = helper(R);

    if(L){
        root->left = NULL;
        root->right = L;
        L_tail->right = R;
    }
    if(R_tail)
        return R_tail;
    if(L_tail)
        return L_tail;

    return root;
}


void flatten(struct TreeNode* root) {
    helper(root);
}             
