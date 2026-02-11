/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head->next == NULL)
        return head;
    int count = 1;
    struct ListNode *cur = head;
    while(cur != NULL && cur->next != NULL){
        cur = cur->next;
        count++;
    }
    cur->next = head;
    cur = head;
    for(int i = 0; i < count - k % count - 1; i++){
        cur = cur->next;
    }
    //printf("count = %d, cur = %d", count, cur->val);
    struct ListNode *ans = cur->next;
    cur->next = NULL;
    
    return ans;
    
}
