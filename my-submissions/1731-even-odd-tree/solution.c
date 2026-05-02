/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isEvenOddTree(struct TreeNode* root) {
    if(root == NULL)
        return true;

    struct TreeNode *queue[100000];
    struct TreeNode *cur = root;
    int levelsize, head = 0, tail = 0 , level_index = 0, prev = -1;
    queue[tail++] = cur;
    while(head < tail){
        levelsize = tail - head;
        printf("No.%d\n", level_index);
        if(level_index % 2 == 0)//odd
           prev = -1;
        else//even
           prev = INT_MAX;

        for(int i = 0; i < levelsize; i++){
            cur = queue[head++];
            //check each value
            //printf("%d ", cur->val);

            if(level_index % 2 == 0){//odd
                if(cur->val % 2 != 1 || cur->val <= prev)
                    return false;
            }
            else{//even
                 if(cur->val % 2 != 0 || cur->val >= prev)
                    return false;
            }
            


            //printf("\n");
                
            if(cur->left) 
                queue[tail++] = cur->left;
        
            if(cur->right)
                queue[tail++] = cur->right;

            prev = cur->val;

        }

        
        level_index++;
    }
    return true;
}
