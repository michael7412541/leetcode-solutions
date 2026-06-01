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

void  dfs(struct TreeNode *root, int sum, int target, int *path, int pathsize, int **answer, int *returnSize, int **returnColumnSizes){
    if(root == NULL)
        return;

    path[pathsize++] = root->val;
    sum += root->val;
    if(root->left == NULL && root->right == NULL)
    {
        if(sum == target){
            (*returnColumnSizes)[(*returnSize)] = pathsize;
            answer[(*returnSize)] = malloc(sizeof(int)*1000);
            for(int i = 0; i < pathsize; i++){
                answer[(*returnSize)][i] = path[i];
            }
            (*returnSize)++;
         }
    }
    dfs(root->left, sum, target, path, pathsize, answer, returnSize, returnColumnSizes);
    dfs(root->right, sum, target, path, pathsize, answer, returnSize, returnColumnSizes);    
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    int **answer = malloc(sizeof(int*) *10000), path[1000];
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int)*1000);
    dfs(root, 0, targetSum, path, 0, answer, returnSize, returnColumnSizes);

    return answer;
}
