/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *dfs(struct TreeNode *root, int target){
    if(root == NULL)
        return NULL;
    struct TreeNode *left = dfs(root->left, target);
    struct TreeNode *right = dfs(root->right, target);

    root->left = left;
    root->right = right;

    if(left == NULL && right == NULL && root->val == target)
        return NULL;

    return root;
    
   
}
struct TreeNode* removeLeafNodes(struct TreeNode* root, int target) {
    if(root == NULL)
        return NULL;


    return dfs(root,target);
}
