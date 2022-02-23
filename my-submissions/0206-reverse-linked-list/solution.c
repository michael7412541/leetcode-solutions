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
    struct ListNode *pre, *nex, *cur;
    pre = NULL;
    cur = head;
    while(cur != NULL){
        //printf("%d ", cur->val);
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
        
    }
    //while(pre != NULL){
    //    printf("%d ", pre->val);
    return pre;
}
