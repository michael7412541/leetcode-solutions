/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countfrom(struct TreeNode *node, long target){
    if(node == NULL)
        return 0;
    int left = countfrom(node->left, target - node->val);
    int right = countfrom(node->right, target - node->val);
    if(target == node->val)
        return left + right + 1;
    else
        return left + right;        
} 
int pathSum(struct TreeNode* root, int targetSum) {
    if(root == NULL)
        return 0;
    return countfrom(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
}
