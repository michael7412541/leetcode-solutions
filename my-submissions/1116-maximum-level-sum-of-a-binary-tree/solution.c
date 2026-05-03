/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLevelSum(struct TreeNode* root) {
    int sum = 0, head = 0, tail = 0, levelsize, max_sum = INT_MIN, max_idx = 0, level_idx = 1;
    struct TreeNode *queue[10000], *cur = root;
    queue[tail++] = cur;

    while(head < tail){
        levelsize = tail - head;
        sum = 0;
        for(int i = 0; i < levelsize; i++){
            cur = queue[head++];
            sum += cur->val;
            if(cur->left)
                queue[tail++] = cur->left;
            if(cur->right)
                queue[tail++] = cur->right;
        }
        if(sum > max_sum){
            max_idx = level_idx;
            max_sum = sum; 
        }
        level_idx++;
    }

    return max_idx;
}
