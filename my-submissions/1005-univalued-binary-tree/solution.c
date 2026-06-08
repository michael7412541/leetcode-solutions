/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool dfs(struct TreeNode *root, int val){
    if(root == NULL)
        return true;
    
    if(root->val == val)
        return dfs(root->left, val) && dfs(root->right, val);
    else
        return false;
}

bool isUnivalTree(struct TreeNode* root) {
    if(root == NULL)
        return true;
    return dfs(root, root->val);

}
