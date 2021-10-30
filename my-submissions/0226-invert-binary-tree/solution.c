/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL)
        return root;
    preorder_traversal(root);
    return root;
}

void preorder_traversal(struct TreeNode* node){
    if(node == NULL)
        return ;
    struct TreeNode *temp;
    printf("%d ", node->val);
    preorder_traversal(node->left);
    preorder_traversal(node->right);
    if(node->left != NULL || node->right != NULL){
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    
    
    return ;
}


