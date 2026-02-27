/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* doubleIt(struct ListNode* head) {
    //step 1 : reverse the linked list
    struct ListNode *prev = NULL;
    struct ListNode *cur = head;
    struct ListNode *next = head;
    struct ListNode *temp;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    cur = prev;
    int carry = 0, sum = 0;
    while(cur){
        sum = cur->val * 2 + carry;
        if(sum >= 10){
            cur->val = sum - 10;
            carry = 1;
        }
        else{
            cur->val = sum;
            carry = 0;
        }
        temp = cur;
        cur = cur->next;
    }

    if(carry > 0){
        struct ListNode *new = malloc(sizeof(struct ListNode));
        new->next = NULL;
        new->val = carry;
        temp->next = new;
    }

    cur = prev;
    prev = NULL;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
    
}
