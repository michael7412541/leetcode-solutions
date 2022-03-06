/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *x1, *x2;
    x1 = head;
    if(head == NULL)
        return false;
    if(head->next)
        if(head->next->next)
            x2 = head->next->next;
        else
            return false;
    else
        return false;
    while(x1 && x1->next && x2->next && x2->next->next != NULL){
        x1 = x1->next;
        x2 = x2->next->next;
        if(x1 == x2)
            return true;
    }
    return false;
}
