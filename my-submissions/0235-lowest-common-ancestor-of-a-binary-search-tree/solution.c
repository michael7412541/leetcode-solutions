/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int small, large;
    if(p->val > q->val){
        //int temp = p->val;//破壞結構
       // p->val = q->val;
       // q->val = temp;
        small = q->val;
        large = p->val;
    }
    else{
        small = p->val;
        large = q->val;
    }
    struct TreeNode *cur = root;
     printf("cur = %d, p = %d, q=%d\n", cur->val, p->val, q->val);
    while(cur != NULL){
        printf("cur = %d, p = %d, q=%d\n", cur->val, p->val, q->val);
        if((cur->val >= small && cur->val <= large) || (cur->val == small || cur->val == large)){
            return cur;
        }
        else if(cur->val > small && cur->val > large){
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }
    }
    return root;
}                                                                                                                                                                                                                                                                                                      
