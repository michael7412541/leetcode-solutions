/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int answer = 0;

struct info{
    int sum;
    int size;
};
struct info dfs(struct TreeNode *node){
    if(node == NULL)
        return (struct info){0, 0};

    struct info left = dfs(node->left);
    struct info right = dfs(node->right);

    int sum = left.sum + node->val + right.sum;
    int size = left.size + right.size + 1;
    if(node->val == sum/size)
        answer++;
    
    return (struct info){sum, size};
}
int averageOfSubtree(struct TreeNode* root) {
    answer = 0;
    dfs(root);

    return answer;
}