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
/*void preorder(struct TreeNode *node, int *arr, int *count) {
    if(node == NULL)
        return;
    arr[(*count)] = node->val;
    (*count)++;
    preorder(node->left, arr, count);
    preorder(node->right, arr, count);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *arr = (int*)malloc(sizeof(int)*100);
    int count = 0;

    preorder(root, arr, &count);
    
    *returnSize = count;
    return arr;
        
}*/

/*int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }
    
    struct TreeNode *stack[100];
    struct TreeNode *cur = root;
    int top = -1, count = 0;
    int *answer = (int*)malloc(sizeof(int) * 100);
    
    stack[++top] = root;
    
    while(top >= 0){
        cur = stack[top--];
        answer[count++] = cur->val;
        
        if(cur->right)
            stack[++top] = cur->right;
        
        if(cur->left)
            stack[++top] = cur->left;
        

        
        
    }
    *returnSize = count;
    return answer;
}*/

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode *cur = root;
    struct TreeNode *stack[100];
    int *answer = malloc(sizeof(int) * 100);
    int top = -1, count = 0;
    
    while(cur || top != -1){
        while(cur){
            stack[++top] = cur;
            answer[count++] = cur->val;
            cur = cur->left;
        }
        
        cur = stack[top--];
        
        cur = cur->right;
    }
    *returnSize = count;
    return answer;
}

