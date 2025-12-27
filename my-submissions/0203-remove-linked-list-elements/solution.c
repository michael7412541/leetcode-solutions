/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//只要「有可能會動到 head」，就該考慮用 dummy
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL)
        return NULL;
    struct ListNode dummy;
    dummy.val = -1;
    dummy.next = head;
    
    struct ListNode *cur = head;
    struct ListNode *prev = &dummy;
    struct ListNode *temp;
    while(cur != NULL){
        //printf("cur = %d, prev = %d\n", cur->val, prev->val);
        if(cur->val == val){
            prev->next = cur->next;
            temp = cur;
            
            cur = cur->next;
            //printf("found");
            free(temp);
        }
        else{
            cur = cur->next;
            prev = prev->next;
        }

    }
    
    return dummy.next;
}
