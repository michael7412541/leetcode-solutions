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

void inorder(struct TreeNode *node, int *arr, int *count) {
    if(node == NULL)
        return;
    
    inorder(node->left, arr, count);
    arr[(*count)] = node->val;
    (*count)++;
    inorder(node->right, arr, count);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *arr = (int*)malloc(sizeof(int)*100);
    int count = 0;

    inorder(root, arr, &count);
    
    *returnSize = count;
    return arr;
}



