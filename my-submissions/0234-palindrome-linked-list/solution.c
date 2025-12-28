/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    struct ListNode *cur = head;
    struct ListNode *next = head;
    struct ListNode *prev = NULL;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev= cur;
        cur = next;
        
    }
    return prev;
    
}
bool isPalindrome(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return true;
    else if(head->next->next == NULL)
        return head->val == head->next->val;
    
    struct ListNode *slow = head, *fast = head;
    struct ListNode *cur = head, *cur1 = NULL;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast == NULL){
        cur1 = reverseList(slow);
    }
    else{
        cur1 = reverseList(slow->next);
    }
    
    while(cur1 != NULL){
        if(cur->val != cur1->val)
            return false;
        cur = cur->next;
        cur1 = cur1->next;
    }
    return true;
    
}
