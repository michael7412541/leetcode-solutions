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
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode *queue[100];
    int head = 0, tail = 0, levelsize;
    struct TreeNode *cur = root;
    queue[tail++] = cur;
    *returnSize = 0;
    int *result = malloc(sizeof(int) * 100);
    while(head < tail){
        levelsize = tail - head;
        for(int i = 0; i < levelsize; i++){
            cur = queue[head++];

            if(cur->left)
                queue[tail++] = cur->left;
            if(cur->right)
                queue[tail++] = cur->right;
            if(i == levelsize - 1)
                result[(*returnSize)++] = cur->val; 
        }
    }

    return result;
}
