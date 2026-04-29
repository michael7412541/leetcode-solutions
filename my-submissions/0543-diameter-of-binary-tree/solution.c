/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int result = 0;
int maxdepth(struct TreeNode *root){
    if(root == NULL)
        return 0;

    int L = maxdepth(root->left);
    int R = maxdepth(root->right);

    if(L + R  > result)
        result = L + R ;

    return L > R ? L + 1 : R + 1;
}
int diameterOfBinaryTree(struct TreeNode* root) {
    result = 0;
    if(root == NULL)
        return 0;
    
    int temp = maxdepth(root);

    return result;
}


