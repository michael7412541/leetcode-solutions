/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    struct TreeNode *queue[2500];
    struct TreeNode *cur = root;
    int left = 0, right = 0, i = 0, j = 0, levelsize;
    int **answer = malloc(sizeof(int*)*2000);
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    *returnSize = 0;
    queue[right++] = root;
    if(root == NULL)
        return NULL;
    while(left < right){
        levelsize = right - left;
        (*returnColumnSizes)[(*returnSize)] = levelsize;
        answer[(*returnSize)] = malloc(sizeof(int)*levelsize);
        
        for(int i = 0; i < levelsize; i++){
            cur = queue[left++];
            answer[(*returnSize)][i] = cur->val;
            
            if(cur->left)
                queue[right++] = cur->left;
            if(cur->right) 
                queue[right++] = cur->right;
        }
        (*returnSize)++;
        
    }
    return answer;
}
