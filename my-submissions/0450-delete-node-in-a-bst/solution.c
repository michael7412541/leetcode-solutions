/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    int dir = 0;
    struct TreeNode* head = root;
    struct TreeNode* prev = NULL;//一開始都要給NULL
    while(head != NULL){
        
        if(key > head->val){
            printf("16");
            prev = head; // <-- 只能在往下走時更新
            head = head->right;
            dir = 0;
        }
        else if(key < head->val){
            prev = head; // <-- 只能在往下走時更新
            printf("21");
            head = head->left;
            dir = 1;
        }
        else{
            if(head->left == NULL && head->right == NULL){
                if(prev == NULL)         // 刪除 root
                    return NULL;
                if(dir == 0)
                    prev->right = NULL;
                else
                    prev->left = NULL;
                return root;
            }
            else if(head->left == NULL && head->right != NULL){
                if(prev == NULL)         // 刪除 root
                    return head->right;
                if(dir == 0){
                    prev->right = head->right;
                    
                }
                else{
                    prev->left = head->right;
                    
                }
                return root;
            }
            else if(head->left != NULL && head->right == NULL){
                if(prev == NULL)         // 刪除 root
                    return head->left;
                if(dir == 0){
                    prev->right = head->left;
                    
                }
                else{
                    prev->left = head->left;
                    
                }
                return root;
            }
            else{
                struct TreeNode* start = head->right;
                struct TreeNode* pstart = head;
                printf(" 52");
                while(start->left != NULL){
                    pstart = start;
                    start = start->left;
                }
                head->val = start->val;
                if(pstart->left == start)
                    pstart->left = start->right;
                else
                    pstart->right = start->right;
                return root;
                
                
                
                
            }
           
           
        }
    }
        
        
    return root;
}
