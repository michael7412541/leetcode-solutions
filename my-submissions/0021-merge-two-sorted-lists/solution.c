/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void sort(struct ListNode* small, struct ListNode* big) {
    
    if(small->next == NULL) {
        small->next = big;
        return;
    }
    if(big == NULL) {
        return;
    }
    
    if(small->next->val > big->val) {
        struct ListNode *node1 = small->next, *node2 = big->next;
        small->next = big;
        big->next = node1;
        sort(big, node2);
    }
    else {
        sort(small->next, big);
    }
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *head;
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;
    if(list1->val <= list2->val) {
        head = list1;
        sort(list1, list2);
    }
    else {
        head = list2;
        sort(list2, list1);
    }
    return head;
}
