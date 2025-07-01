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

void postorder(struct TreeNode *node, int *arr, int *count) {
    if(node == NULL)
        return;
    
    postorder(node->left, arr, count);
    
    postorder(node->right, arr, count);
    arr[(*count)] = node->val;
    (*count)++;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *arr = (int*)malloc(sizeof(int)*100);
    int count = 0;

    postorder(root, arr, &count);
    
    *returnSize = count;
    return arr;
}




