/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max = 0;
int max_depth(struct TreeNode *root){
    if(root == NULL)
        return 0;
    
    int right = max_depth(root->right);
    int left = max_depth(root->left);
    if(left + right > max)
        max = left + right;

    return (left > right ? left : right) + 1;
} 
int diameterOfBinaryTree(struct TreeNode* root) {
    max = 0;
    if(root == NULL)
        return 0;
    
    int temp = max_depth(root);
    return max;
}
