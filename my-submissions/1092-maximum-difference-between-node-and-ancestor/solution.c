/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max_diff = 0;

void dfs(struct TreeNode *root, int min, int max){
    if(root == NULL)
        return ;
    
    if(abs(root->val - max) > max_diff)
        max_diff = abs(root->val - max);
    if(abs(root->val - min) > max_diff)
        max_diff = abs(root->val - min);
    
    if(root->val > max)
        max = root->val;
    if(root->val < min)
        min = root->val;

    dfs(root->left, min, max);
    dfs(root->right, min, max);
}

int maxAncestorDiff(struct TreeNode* root) {
    max_diff = 0;
    if(root == NULL)
        return 0;
    dfs(root, root->val, root->val);
    return max_diff;
}
