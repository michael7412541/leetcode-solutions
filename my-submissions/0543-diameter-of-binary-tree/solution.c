/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max = INT_MIN;



int helper(struct TreeNode *root){
    if(root == NULL)
        return 0;
    
    int left = helper(root->left);
    int right = helper(root->right);

    if(left + right > max)
        max = left + right;

    return (left > right ? left : right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    max = 0;
    int c = helper(root);
    return max;
}
