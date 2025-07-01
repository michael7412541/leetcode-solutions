/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void preorder(struct TreeNode *node, int *arr, int *count) {
    if(node == NULL)
        return;
    arr[(*count)] = node->val;
    (*count)++;
    preorder(node->left, arr, count);
    preorder(node->right, arr, count);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *arr = (int*)malloc(sizeof(int)*100);
    int count = 0;

    preorder(root, arr, &count);
    
    *returnSize = count;
    return arr;
        
}
