/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void print_node(struct ListNode* head){
    if(head == NULL)
        return ;
    printf("%d ", head->val);
    print_node(head->next);
}

struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode* dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    
    struct ListNode* select = head; 
    struct ListNode* origin = dummy; 
    struct ListNode* Next = NULL; 
    if(head == NULL) 
        return head;
    
    
    select = head;//select
    
    while(select != NULL){
       // origin = head; //compare
        Next = select->next;
        while(origin->next != NULL && select->val > origin->next->val){
            origin = origin->next;
        }
        
        // 1 2 "3" 5 7  <==4
        //       "4"
        select->next = origin->next;
        origin->next = select;
        
        origin = dummy;
        select = Next;
        
        
    }
    print_node(head);
    return dummy->next;
}


