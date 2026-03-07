/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
	if(root == NULL)
        return NULL;
    
    struct Node *queue[5000], *prev = NULL, *cur;
    int level = 0, head = 0, tail = 0;
    queue[tail++] = root;
    while(head < tail){
        int levelsize = tail - head;
        //prev = NULL;
        for(int i = 0; i < levelsize; i++){
            cur = queue[head++];
            if(i > 0)
                prev->next = cur;
         
            if(cur->left)
                queue[tail++] = cur->left;
            if(cur->right)
                queue[tail++] = cur->right;
            
            prev = cur;
        }

        cur->next = NULL;
        
    }
    
    return root;
}
