/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max_depth(struct TreeNode *root){
    if(root == NULL)
        return 0;
    int L = max_depth(root->left);
    int R = max_depth(root->right);
    printf("root = %d, L = %d, R = %d\n", root->val, L, R);
    return (L > R ? L : R) + 1;
} 
bool isBalanced(struct TreeNode* root) {
    if(root == NULL)
        return true;
    int L = max_depth(root->left);
    int R = max_depth(root->right);
    if(abs(L - R) > 1)
        return false;
    else
        return isBalanced(root->left) && isBalanced(root->right);
}
