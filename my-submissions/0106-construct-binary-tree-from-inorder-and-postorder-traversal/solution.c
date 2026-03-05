/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* construct_Tree(int * inorder, int inleft, int inright, int* postorder, int postleft, int postright, int* hash){
    if(inright < inleft || postright < postleft)
        return NULL;
    
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = postorder[postright];
    int pIndex = hash[root->val + 3000];
    root->left = construct_Tree(inorder, inleft, pIndex- 1, postorder, postleft, postleft + pIndex - inleft - 1, hash);
    root->right =  construct_Tree(inorder, pIndex+ 1, inright, postorder, postleft + pIndex - inleft, postright - 1, hash);   
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    
    int hash[6000];
    for(int i = 0; i < inorderSize; i++){
        hash[inorder[i] + 3000] = i;
    }

    return construct_Tree(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1, hash);
}
