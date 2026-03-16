/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    int mid = numsSize/2, left = mid - 1, right = mid + 1;
    //if(left < 0 || right > numsSize - 1)
    //    return NULL;
    
    if(numsSize <= 0)
        return NULL;
    
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = sortedArrayToBST(nums, mid);
    node->right = sortedArrayToBST(&(nums[right]),numsSize - right);
    
    return node;
}
