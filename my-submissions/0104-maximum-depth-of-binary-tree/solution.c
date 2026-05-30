/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return (left > right ? left : right) + 1;

}













/*
因為：

狀況	L	R	結果
兩邊都有	>0	>0	正常比較
左邊空	0	>0	取 R
右邊空	>0	0	取 L
都空 (leaf)	0	0	0 + 1 = 1

你原本的 4 個 if 分支，其實全部被 max() 自動處理了。

🧠 面試官看什麼？

這題是 Binary Tree recursion 基本功測驗題。

他想看你是否：

知道 tree recursion 模板

能不能抽象出「一層 + 子問題」

如果你寫一堆分支，會讓人覺得：

你在 case by case 解，而不是理解 tree structure
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    
    int L = maxDepth(root->left);
    int R = maxDepth(root->right);
    
    return (L > R ? L : R) + 1;
}*/
