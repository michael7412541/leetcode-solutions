/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNodes(struct ListNode* head) {
    int max = 0;
    struct ListNode *cur = head;
    struct ListNode *prev = NULL;
    struct ListNode *next = head;
    struct ListNode dummy;
    dummy.next = NULL;

    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    cur = prev;
    
    
    while(cur){
        if(dummy.next == NULL){
            //printf("%d ", cur->val);
            max = cur->val;
            next = cur->next;
            
            cur->next = dummy.next;
            dummy.next = cur;
            cur = next;
            
            printf("*%d , mqax = %d\n", cur->val, max);
            
        }
        else if(cur->val >= max){
            printf("*%d , mqax = %d\n", cur->val, max);
            max = cur->val;
            next = cur->next;
            cur->next = dummy.next;
            dummy.next = cur;
            cur = next;
            
        }
        else{
            printf("*%d , mqax = %d\n", cur->val, max);
            cur = cur->next;
        }
    }

    return dummy.next;
}
