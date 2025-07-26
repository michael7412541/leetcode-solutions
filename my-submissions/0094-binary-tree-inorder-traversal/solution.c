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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode *stack[100];
    int *answer = (int*)malloc(sizeof(int)*100);
    int top = -1, count = 0;
    struct TreeNode *cur;
    cur = root;
    
    while(cur != NULL || top != -1){
        while(cur != NULL){
            stack[++top] = cur;
            cur = cur->left;
        }
        
        cur = stack[top--];
        answer[count] = cur->val;
        count++;
        
        cur = cur->right;
            
    }
    
    *returnSize = count;
    
     
    return answer;
}
