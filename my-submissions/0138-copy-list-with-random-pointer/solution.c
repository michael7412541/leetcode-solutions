/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
	if(head == NULL)
        return head;
    struct Node dummy;
    dummy.next = NULL;
    struct Node *cur = head;
    
    while(cur){
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->val = cur->val;
        newNode->next = cur->next;
        newNode->random = NULL;
        cur->next = newNode;
        cur = newNode->next;
    }
    cur = head;
    while(cur){
        if(cur->random)
            cur->next->random = cur->random->next;
        else
            cur->next->random = NULL;
        cur = cur->next->next;
    }
    cur = head;
    struct Node *newhead = cur->next;
    while(cur){
        struct Node *copy = cur->next;
        cur->next = copy->next;
        
        if(copy->next)
            copy->next = copy->next->next;
        
        cur = cur->next;
    }
    
    return newhead;
}
