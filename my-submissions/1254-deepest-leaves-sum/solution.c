/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int deepestLeavesSum(struct TreeNode* root) {
    struct TreeNode *queue[10000], *cur;
    int i = 0, levelsize = 0, head = -1, tail = -1, sum = 0;
    queue[++tail] = root;
    while(head < tail){
        levelsize = tail - head;
        
        sum = 0;
        for(i = 0; i < levelsize; i++){
            cur = queue[++head];
            sum += cur->val;
            if(cur->left)
                queue[++tail] = cur->left;
            if(cur->right)
                queue[++tail] = cur->right;
        }
    }
    return sum;
}
