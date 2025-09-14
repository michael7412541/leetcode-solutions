/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int calculate_depth(struct TreeNode* node, int count) {
    if(node == NULL)
        return count;
    else
        count++;
    int r = calculate_depth(node->right, count);
    int l = calculate_depth(node->left, count);
    if(r > l)
        return r;
    else
        return l;
}
int maxDepth(struct TreeNode* root) {
    return calculate_depth(root, 0);
}
