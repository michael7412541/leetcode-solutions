/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode *list){
    if(list == NULL)
        return list;
    struct ListNode *temp, *cur = list, *result = NULL;
    //result->next = NULL;
    while(cur != NULL){
        temp = cur->next;
        cur->next = result;
        result = cur;
        cur = temp;
    }

    return result;

}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *r1 = reverse(l1);
    struct ListNode *r2 = reverse(l2);
    struct ListNode *c1, *c2, *result = NULL;
    struct ListNode dummy;
    dummy.next = NULL;
    result = &dummy;
    c1 = r1;
    c2 = r2;
    int carry = 0, sum = 0;
    while(c1 != NULL || c2 != NULL || carry != 0){
        sum = carry;
        if(c1 != NULL){
            sum += c1->val;
            c1 = c1->next;
        }

        if(c2 != NULL){
            sum += c2->val;
            c2 = c2->next;
        }
        struct ListNode *temp = malloc(sizeof(struct ListNode));
        temp->val = sum % 10;
        carry = sum / 10;
        result->next = temp;
        temp->next = NULL;
        result = temp;
    }

    

    return reverse(dummy.next);

}
