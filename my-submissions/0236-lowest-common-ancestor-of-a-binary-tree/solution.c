/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
   /*(root == NULL)
        return NULL;
    else if(root == p)
        return p;
    else if(root == q)
        return q;
    else if(lowestCommonAncestor(root->left, p, q) != NULL && lowestCommonAncestor(root->right, p, q) != NULL){
        return root;
    }
    else
        return root;
    */
    if(root == NULL)
        return NULL;
    
    if(root == p || root == q)
        return root;
    
    struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *right = lowestCommonAncestor(root->right, p, q);
    
    if(left == NULL && right == NULL)
        return NULL;
    else if(left == NULL && right != NULL){
        return right;
    }
    else if(left != NULL && right == NULL){
        return left;
    }
    else{
        return root;
    }
    
}
