/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    struct ListNode *cur = head;
    int answer = 0;
    while(cur){
        answer = answer * 2 + cur->val;
        cur = cur->next;
    }

    return answer;
}
