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
int max_count = 0;
int prev;
int count = 0;


void helper(struct TreeNode *root, int *result, int* returnSize) {
    if(root == NULL)
        return ;

    helper(root->left, result, returnSize);
    printf("%d ", root->val);
    if(prev == -200000){
        count = 1;
        prev = root->val;
        max_count = 1;
    }
    else if(prev == root->val){
        count++;
    }
    else{
        count  = 1;
    }
    
    if(count > max_count){

        *returnSize = 0;
        max_count = count;
        result[(*returnSize)++] = root->val;
    }
    else if(count == max_count){
        result[(*returnSize)++] = root->val;
    }
    prev = root->val;

    helper(root->right, result, returnSize);
    
    
}

int* findMode(struct TreeNode* root, int* returnSize) {
    prev = -200000;
    *returnSize = 0;
    int *result = malloc(sizeof(int) * 10000);
    helper(root, result, returnSize);

    return result;
}
