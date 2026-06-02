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
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }
    struct TreeNode *queue[2000], *cur = NULL;
    int head = -1, tail = -1, levelsize = 0;
    queue[++tail] = root;

    int **answer = malloc(sizeof(int*)*2000);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int)*2000);

    while(head < tail){
        levelsize = tail - head;
        answer[*returnSize]  = malloc(sizeof(int)*levelsize);
        (*returnColumnSizes)[*returnSize] = levelsize;
        
        for(int i = 0; i < levelsize; i++){
            cur =queue[++head];
            if((*returnSize) % 2 == 0){
                answer[(*returnSize)][i] = cur->val; 
            }
            else{
                answer[(*returnSize)][(levelsize - i - 1)] = cur->val; 
            }

            if(cur->left) queue[++tail] = cur->left;
            if(cur->right) queue[++tail] = cur->right;
            
        }
        (*returnSize)++;
    }
    return answer;
}
