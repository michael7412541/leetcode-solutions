/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    /*if(root == p || root == q || root == NULL)
        return root;
    
    struct TreeNode *L = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *R = lowestCommonAncestor(root->right, p, q);
    
    if(L != NULL && R != NULL)
        return root;
    else
        return L == NULL ? R : L;*/
    if(root == NULL)
        return NULL;
    
    int small = 0,large = 0;
    small = p->val > q->val ? q->val : p->val;
    large = p->val > q->val ? p->val : q->val;
    if(root->val >= small && root->val <= large)
        return root;
    else if(root->val > small && root->val > large){
        return lowestCommonAncestor(root->left, p, q); 
    }
    else{
        return lowestCommonAncestor(root->right, p, q);
    }
}                                                                                                                                                                                                                                                                                                      
