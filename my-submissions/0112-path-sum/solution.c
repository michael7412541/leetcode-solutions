/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root == NULL)
        return false;
    else{
        if(root->left == NULL && root->right == NULL && root->val == targetSum)
            return true;
        else
            return (hasPathSum(root->left, targetSum - root->val) 
                    || hasPathSum(root->right, targetSum - root->val));
    }
}

/*2️⃣ leaf + 剛好等於 target
if(root->left == NULL && root->right == NULL && root->val == targetSum)
    return true;

這段很關鍵。

⚠️ 很多人會忘記「一定要是 leaf」。

這題是：

root-to-leaf path

不是任意 path。

你有檢查 leaf，這點非常好 👍
*/
