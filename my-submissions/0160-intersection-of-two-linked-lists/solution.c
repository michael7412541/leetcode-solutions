/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *cur1 = headA, *cur2 = headB;
    int done = 0;
    while((done <= 2) && (cur1 || cur2)){
        //printf("cur1 = %d, cur2 = %d\n", cur1->val, cur2->val);
        if(cur1 == cur2)
            return cur1;
        
        if(cur1 == NULL){
            cur1 = headB;
            done++;
        }
        else{
            cur1 = cur1->next;
        }
        
        if(cur2 == NULL){
            cur2 = headA;
            done++;
        }
        else{
            cur2 = cur2->next;
        }
    }
    return NULL; 
}
