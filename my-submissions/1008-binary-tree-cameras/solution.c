/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int count = 0;
struct State{
    int camera;
    int coverd;
};
// 0 沒有camera 也沒有covered
// 1 沒有camera 但有被covered
// 2 有camera
int dfs(struct TreeNode* node){
    if(node == NULL){
        return 1;
    }
    int left = dfs(node->left);
    int right = dfs(node->right);


    if(left == 0 || right == 0){
        count++;
        return 2;
    }
    else if(left == 2 || right == 2){
        return 1;
    }
    else{
        return 0;
    }

}
int minCameraCover(struct TreeNode* root) {
    count = 0;
    int result = dfs(root);
    if(result == 0)
        return ++count;
    else
        return count;
}
