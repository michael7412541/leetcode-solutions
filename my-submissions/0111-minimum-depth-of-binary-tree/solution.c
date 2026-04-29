/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if(left == 0 && right == 0)
        return 1;
    else if(left != 0 && right != 0)
        return left > right ? right + 1 :left + 1;
    else
        return left == 0 ? right + 1 : left + 1;
    
}
