/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool isSame(struct TreeNode* root, struct TreeNode* subRoot) {
    if(root == NULL && subRoot == NULL){
        return true;
    }
    else if(root != NULL && subRoot != NULL){
         if(root->val == subRoot->val){
                return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
        }
        else
            return false;
    }
    else
        return false;
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    struct TreeNode *cur;
    struct TreeNode *stack[2000];
    bool answer = false, answer1 = false, answer2 = false;
    int top = -1;
    stack[++top] = root;
    while(top >= 0){
        cur = stack[top--];
        answer = isSame(cur, subRoot);

        if(cur->left){
            //answer1 = isSame(cur->left, subRoot);
            stack[++top] = cur->left;
        }
        if(cur->right){
            //answer2 = isSame(cur->right, subRoot);
            stack[++top] = cur->right;
        }

        if(answer || answer1 || answer2)
            return true;
    }
    return answer;
}
