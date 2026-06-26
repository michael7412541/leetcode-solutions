/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *dfs(struct TreeNode* node1, struct TreeNode *node2){
    if(node1 != NULL && node2 != NULL){
        node1->val += node2->val;
        node1->left = dfs(node1->left, node2->left);
        node1->right = dfs(node1->right, node2->right);
        return node1;
    }
    else if(node1 != NULL){//node2 = NULL
        return node1;
    }
    else if(node2 != NULL){
        return node2;
    }
    else{
        return NULL;
    }
}

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    return dfs(root1, root2);
}
