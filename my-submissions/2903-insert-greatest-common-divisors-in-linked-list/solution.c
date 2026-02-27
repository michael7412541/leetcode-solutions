/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 
int find_divisor(int a, int b);
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    struct ListNode *next = head;
    struct ListNode *cur = head;
    while(cur->next){
        next = cur->next;
        struct ListNode *new = malloc(sizeof(struct ListNode));
        new->next = next;
        cur->next = new;
        printf("%d %d\n",cur->val, next->val );
        new->val = find_divisor(cur->val, next->val);
        cur = new->next;
    }

    return head;
}

/*int find_divisor(int a, int b){
    int temp = a;
    if(b > a){
        a = b;
        b = temp;
    }
    if(a % b == 0){
        return b;
    }
    else{
        return find_divisor(a - a/b * b, b);//遞迴要加上return
    }
    return -1;
}*/
int find_divisor(int a, int b){
    if (b == 0)
        return a;
    return find_divisor(b, a % b);
}
