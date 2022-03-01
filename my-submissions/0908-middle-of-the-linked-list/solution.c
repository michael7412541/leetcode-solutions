/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    int i = 0, count = 0;
    struct ListNode *current;
    current = head;
    while(current != NULL){
        current = current->next;
        count++;
    }
    current = head;
    if(count % 2 == 0){
        for(i = 0; i < (count/2) ; i++)
            current = current->next;
    }
    else{
        for(i = 0; i < (count/2) ; i++)
            current = current->next;
    }
    return current;
}
