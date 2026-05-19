/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy, *cur, *prev, *next;
    dummy.val = -1;
    dummy.next = head;
    cur = head;
    prev = &dummy;
    int bypass = 0;
    while(cur != NULL){
        bypass = 0;
        next = cur->next;
        while(next != NULL && cur->val == next->val){
            next = next->next;
            bypass = 1;
        }
        //printf("prev = %d, cur = %d, next = %d\n", prev->val, cur->val, next->val);
        if(bypass == 1){
            prev->next = next;
            cur = prev->next;
        }
        else{
            prev = cur;
            cur = cur->next;
            
        }
    }

    return dummy.next;
}
