/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct State{
    int skip;
    int rob;
};
int max(int a, int b){
    return a > b ? a : b;
}
struct State dfs(struct TreeNode *node){
    if(node == NULL)
        return (struct State){0,0};
    
    struct State left = dfs(node->left);
    struct State right = dfs(node->right);
    struct State result;
    result.skip = max(left.rob, left.skip) + max(right.rob, right.skip);
    result.rob = node->val + left.skip + right.skip;
    
    return result;
}

int rob(struct TreeNode* root) {
    
    struct State answer = dfs(root);
    return max(answer.skip, answer.rob);
}
