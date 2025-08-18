/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reverse(struct ListNode **node) {
    if(*node == NULL || (*node)->next == NULL)
        return;
    else {
        struct ListNode *temp = (*node)->next;
        (*node)->next = (*node)->next->next;
        temp->next = *node;
        *node = temp;
        //node->val = node->next->val;
        //node->next->val = temp;
         reverse(&((*node)->next->next));//reverse(node->next->next);
    }
}

struct ListNode* swapPairs(struct ListNode* head) {
    //struct ListNode *node = head;
    reverse(&head);
    return head;
    
}
