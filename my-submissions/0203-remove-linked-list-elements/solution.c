/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void print_node(struct ListNode * node){
    while(node != NULL){
        printf("%d ", node->val);
        node = node->next;
    }
}

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *head_ref, *head_1;
    if(head == NULL)
        return head;
    head_ref = head; //NODE 1 = 7
    head_1 = head->next; //NODE 2 = null
    while(head != NULL){
        if(head_ref->val == val){
            head_ref = head_ref->next; //NODE 2 = null
            head = head_ref; // NODE 2 =null
            if(head != NULL){
                head_1 = head->next;
            }
        }
        else if(head_1 == NULL){
            break;
        }
        else if(head_1->val == val){
            head->next = head_1->next;
        }
        else
            head = head->next;
            if(head != NULL){
                head_1 = head->next;
            }

                    
    }
    print_node(head);
    return head_ref;
}
