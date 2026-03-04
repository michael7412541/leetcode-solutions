/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTree1(int* preorder, int preleft, int preright, int *map, int* inorder, int inleft, int inright){
    if(preleft > preright || inleft > inright){
        return NULL;
    }
    
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    int pIndex = map[preorder[preleft] + 3000];
    root->val = preorder[preleft];
    root->left = buildTree1(preorder, preleft + 1, preleft + pIndex - inleft, map, inorder, inleft, pIndex - 1); 
    root->right = buildTree1(preorder, preleft + pIndex - inleft + 1, preright, map, inorder, pIndex + 1, inright);
        
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int hash[6000];
    for(int i = 0; i < inorderSize; i++){
        hash[inorder[i] + 3000] = i;
    }
    return buildTree1(preorder, 0, preorderSize - 1, hash, inorder, 0, inorderSize - 1);
}
