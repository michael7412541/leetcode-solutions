/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


    
bool preorder_traversal(struct TreeNode *node1, struct TreeNode *node2){
    bool a, b;
    if(node1 != NULL && node2 == NULL) return false;
    else if(node1 == NULL && node2 != NULL) return false;
    else if (node1 == NULL && node2 == NULL) return true;
    else if(node1->val == node2-> val){
        a = preorder_traversal(node1->left, node2->right);
        b = preorder_traversal(node1->right, node2->left);
        
        return a*b;
    }
    else return false;
        
    
}


bool isSymmetric(struct TreeNode* root){
    
    return preorder_traversal(root, root);
}
