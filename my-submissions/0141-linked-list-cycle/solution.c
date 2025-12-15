/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL)
        return false;
    struct ListNode *slow = head, *fast = head;
    //while(slow != NULL && fast != NULL){
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow != NULL && fast != NULL && slow == fast){
            return true;
        }
    }
    return false;
}
