/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;
    while(list1 || list2){
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        if((list1 == NULL && list2 != NULL)|| (list2 != NULL && list1->val > list2->val)){
            newNode->val = list2->val;
            list2 = list2->next;
        }
        else{
            newNode->val = list1->val;
            list1 = list1->next;
        }
        tail->next = newNode;
        tail = newNode;
    }
    return dummy.next;
}
