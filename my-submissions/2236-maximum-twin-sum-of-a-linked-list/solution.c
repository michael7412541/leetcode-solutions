/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {

    if(head->next->next == NULL)
        return (head->val + head->next->val);

    struct ListNode *slow = head;
    struct ListNode *fast = head->next->next;
    int arr[100000] = {0}, count = 0, max = 0, mid = 0;

    while(slow){
        if(fast){
            arr[count] = slow->val;
            count++;
            if(fast)
                fast = fast->next->next;
        }
        else{
            if(mid == 0){
                arr[count] = slow->val;
                mid = count;
            }
            else{
                arr[count] += slow->val;
                if(arr[count] > max)
                    max = arr[count];
                count--;
            }
        }
        slow = slow->next;
    }

    return max;
}
