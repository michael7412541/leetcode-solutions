/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int answer = 0;
struct State{
    int left_path;
    int right_path;
};
int max(int a, int b, int c){
    if(a >= b && a >= c) return a;
    else if(b >= a && b >= c) return b;
    else return c;
}
struct State dfs(struct TreeNode *node){
    struct State result;
    if(node == NULL)
        return (struct State){0, 0};
    struct State left = dfs(node->left);
    struct State right = dfs(node->right);
    result.left_path = left.right_path + 1;
    result.right_path = right.left_path + 1;
    answer = max(answer, result.left_path, result.right_path);
    return result;
}
int longestZigZag(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    answer = 0;
    struct State temp = dfs(root);
    return --answer;
}
