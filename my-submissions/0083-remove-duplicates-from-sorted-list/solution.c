/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL)
        return head;
    struct ListNode *current, *next1;
    current = head;
    next1 = current -> next;
    while(next1 != NULL){
        if(current->val == next1->val){
        // delete next1 node
            current->next = next1->next;
            next1 = current->next;
        }
        else{
            current = current->next;
            next1 = current->next;
        }
    }
    return head;
}
