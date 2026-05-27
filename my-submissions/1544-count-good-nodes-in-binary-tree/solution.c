/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int count = 0;
void helper(struct TreeNode *root, int val){
    if(root == NULL)
        return;
    if(root->val >= val){
        count++;
        printf("roott->val: %d, val:%d\n", root->val, val);
        helper(root->left, root->val);
        helper(root->right, root->val);
    }
    else{
        helper(root->left, val);
        helper(root->right, val);
    }
    return ;
}
int goodNodes(struct TreeNode* root){
    count = 0;
    if(root == NULL)
        return 0; 
    helper(root, INT_MIN);
    return count;
}
