/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isMirror(struct TreeNode *tree1, struct TreeNode *tree2){
    if(tree1 == NULL && tree2 == NULL)
        return true;
    else if(tree1 != NULL && tree2 != NULL){
        if(tree1->val == tree2->val)
            return isMirror(tree1->left, tree2->right) && isMirror(tree1->right, tree2->left);
        else
            return false;
    }
    else
        return false;
}

bool isSymmetric(struct TreeNode* root) {
    if(root->right != NULL && root->left != NULL)
        return isMirror(root->left, root->right);
    else if(root->right == NULL && root->left == NULL)
        return true;
    else
        return false;
}
