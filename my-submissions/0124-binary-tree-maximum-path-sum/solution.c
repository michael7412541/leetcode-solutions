/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max = 0;

int dfs(struct TreeNode *node){
    if(node == NULL)
        return 0;

    int left = dfs(node->left);
    int right = dfs(node->right);


    int temp = node->val;
    if(left >= 0)
        temp += left;
    if(right >= 0)
        temp += right;
    
    if(temp > max)
        max = temp;

    if(left <= 0 && right <= 0)
        return node->val;
    else
        return (left > right ? left : right) + node->val; 
}


int maxPathSum(struct TreeNode* root) {
    
    if(root == NULL)
        return 0;
    max = root->val;
    dfs(root);
    return max;
}
