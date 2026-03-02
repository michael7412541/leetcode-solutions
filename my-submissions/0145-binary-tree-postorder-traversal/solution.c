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

/*void postorder(struct TreeNode *node, int *arr, int *count) {
    if(node == NULL)
        return;
    
    postorder(node->left, arr, count);
    
    postorder(node->right, arr, count);
    arr[(*count)] = node->val;
    (*count)++;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *arr = (int*)malloc(sizeof(int)*100);
    int count = 0;

    postorder(root, arr, &count);
    
    *returnSize = count;
    return arr;
}*/

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    struct TreeNode *stack[100];
    struct TreeNode *cur = root, *prev = NULL;
    int *answer = malloc(sizeof(int) * 100);
    int top = -1, count = 0;
    
    while(cur != NULL || top != -1){
        while(cur){
            stack[++top] = cur;
            cur = cur->left;
        }
        
        struct TreeNode *node = stack[top];
        if(node->right != NULL && prev != node->right){
            cur = node->right;    
        }
        else{
            prev = node;
            answer[count++] = node->val;
            top--;
        }
        
    }
    *returnSize = count;
    return answer;
}




