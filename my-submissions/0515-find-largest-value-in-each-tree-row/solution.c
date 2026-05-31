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
int* largestValues(struct TreeNode* root, int* returnSize) {
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }
    int max, i = 0, levelsize = 0, head = -1, tail = -1;
    int *answer = malloc(sizeof(int) * 100000);
    *returnSize = 0;
    struct TreeNode *queue[100000], *temp;
    queue[++tail] = root;
    while(head < tail){
        levelsize = tail - head;
        max = INT_MIN;
        for(i = 0; i < levelsize; i++){
            temp = queue[++head];
            if(temp->val > max)
                max = temp->val;

            if(temp->left != NULL)
                queue[++tail] = temp->left;
            if(temp->right != NULL)
                queue[++tail] = temp->right;
        }
        answer[(*returnSize)++] = max;
    }
    return answer;
}
