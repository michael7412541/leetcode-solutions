/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int answer;
//state定義為跟這個node值相同的longest path
struct State{
    int path;
};
int max(int a, int b ,int c){
    if(a >= b && a >= c) return a;
    else if(b >= a && b >= c) return b;
    else return c;
}
struct State dfs(struct TreeNode *node){
    struct State result;
    if(node == NULL) return (struct State){0};

    struct State left = dfs(node->left);
    struct State right = dfs(node->right);
    result.path = 0;

    if(node->left != NULL && node->val == node->left->val)
        result.path = left.path + 1;
   if(node->right != NULL && node->val == node->right->val) {
        int right_path_val = right.path + 1;
        if(right_path_val > result.path)
            result.path = right_path_val;
    }
    int temp = 0;

    if(result.path != 0 && node->left && node->right && node->left->val == node->right->val && node->left->val == node->val)
        temp = left.path + right.path + 2;
    answer = max(result.path, temp, answer);

    return result;
}

int longestUnivaluePath(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    answer = 0;
    struct State result = dfs(root);
    return answer;
}
