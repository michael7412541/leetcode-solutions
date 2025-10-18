/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool helper(struct TreeNode* root, long max, long min)
{
    if(root == NULL)
        return true;
    
    if(root->val > min && root->val < max)
        return helper(root->left, root->val, min) && helper(root->right, max, root->val);
    else
        return false;
   
    
        
}
bool isValidBST(struct TreeNode* root) {
    return helper(root, LONG_MAX, LONG_MIN);
}


