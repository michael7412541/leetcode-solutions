/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max = 0;
int helper(struct TreeNode* root, int val){
    if(root == NULL)
        return 0;
    
    if(root->val == val){
        int left = helper(root->left, val);
        int right = helper(root->right, val);
    
        if(left + right > max)
            max = left + right;

        return (left > right ? left : right) + 1;
    }
    else{
        int left = helper(root->left, root->val);
        int right = helper(root->right, root->val);
    
        if(left + right > max)
            max = left + right;

        return 0;
    }
   
    
}


int longestUnivaluePath(struct TreeNode* root) {
    max = 0;
    if(root == NULL)
        return 0;
    helper(root, root->val);
    return max;
}
