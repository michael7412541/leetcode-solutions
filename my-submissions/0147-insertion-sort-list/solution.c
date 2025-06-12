/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    struct ListNode *curr = head;
    
    while(curr)
    {
        struct ListNode *next = curr->next;
        
        struct ListNode *prev = &dummy;
        while(prev->next != NULL && prev->next->val < curr->val)
        {
            prev = prev->next;
        }
        
        
        curr->next = prev->next;
        prev->next = curr;
        
        curr = next;
    }
    
    return dummy.next;
}
