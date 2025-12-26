/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
struct ListNode* reverse(struct ListNode **node, int count) {
    if(*node == NULL)
        return NULL;
    if(count == 0 && (*node)->next == NULL)
       return *node;
    struct ListNode *p = *node, *prev = NULL;
    for(int i = 0; i < count && p != NULL; i++) {
        prev = p;
        p = p->next;
    }
    if(p == NULL)
        return *node;
    
    if (prev != NULL)
        prev->next = p->next;
    p->next = *node;
    *node = p;
    
    return reverse(node, count+1);
}
struct ListNode* reverseList(struct ListNode* head) {
    return reverse(&head, 0);
}
struct ListNode* reverse(struct ListNode **head, int count) {
    if (*head == NULL || (*head)->next == NULL) 
        return *head;

    struct ListNode *p = *head;
    struct ListNode *prev = NULL;

    // 從 head 走 count 步
    for (int i = 0; i < count && p != NULL; i++) {
        prev = p;
        p = p->next;
    }

    // 如果已經走到尾端，結束遞迴
    if (p == NULL)
        return *head;

    // 將 p 從原來位置移除
    if (prev != NULL)
        prev->next = p->next;

    // 將 p 插到前面
    p->next = *head;
    *head = p;

    // 遞迴呼叫，count 保持不變，下一個未處理節點會在 for 迴圈中被找到
    return reverse(head, count + 1);
}

struct ListNode* reverse(struct ListNode *head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    struct ListNode* node = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return node;
}

struct ListNode* reverseList(struct ListNode* head) {
    return reverse(head);
}*/

struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    struct ListNode *cur = head;
    struct ListNode *next = head;
    struct ListNode *prev = NULL;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev= cur;
        cur = next;
        
    }
    return prev;
    
}


