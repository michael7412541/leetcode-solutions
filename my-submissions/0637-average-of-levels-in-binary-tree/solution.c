/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    if(root == NULL)
        return NULL;
    struct TreeNode *queue[10000];
    struct TreeNode *cur;
    double *result = malloc(sizeof(double) * 10000);
    int levelsize, head = 0, tail = 0;
    double sum;
    cur = root;
    queue[tail++] = cur;
    (*returnSize) = 0;
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
        result[(*returnSize)++] = sum/levelsize;
    }
    return result;

}
