/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)
        return head;
    struct ListNode *a, *b, *c;
    a = NULL;
    b = head;
    
    while(c != NULL){
        c= b->next;
        b->next = a;
        a = b;
        b = c;
        
    }
    head = a;
    return head;
}
