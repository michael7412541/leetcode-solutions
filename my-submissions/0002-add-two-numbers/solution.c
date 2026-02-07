/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;
    int carry = 0, sum = 0;
    
    while(l1 != NULL || l2 != NULL || carry != 0){
        sum = carry;
        if(l1 != NULL){
            sum += l1->val;
            l1 = l1->next;
        }
        
        if(l2 != NULL){
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        
        tail->next = newNode;//先把尾吧接到心結點
        tail = newNode;//再把尾吧移動到最後一個
        
        
    }
    
    
    
    
    return dummy.next;
}
