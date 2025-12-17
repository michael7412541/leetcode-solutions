/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL)
        return NULL;
    int count = -1; 
    struct ListNode *slow = head, *fast = head;
    //while(slow != NULL && fast != NULL){
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow != NULL && fast != NULL && slow == fast){
            count++;
            break;
        }
    }
    
    if(count == -1)
        return NULL;
    
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
        count++;
    }
    return slow;
    
    
}




