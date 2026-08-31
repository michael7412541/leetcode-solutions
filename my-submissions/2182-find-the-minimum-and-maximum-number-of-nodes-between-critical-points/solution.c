/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int *answer = malloc(sizeof(int) * 2);
    *returnSize = 2;
    if(head == NULL || head->next == NULL){
        answer[0] = -1;
        answer[1] = -1;
        return answer;
    }
    int count = 0, first_idx = -1, last_idx = -1, min = INT_MAX;
    struct ListNode *cur = head->next, *prev = head;
    while(cur != NULL && cur->next != NULL){
        int prev_val = prev->val;
        int cur_val = cur->val;
        int next = cur->next->val;
        if((prev_val - cur_val < 0 && cur_val - next > 0) || (prev_val - cur_val > 0 && cur_val - next < 0)){
            if(first_idx == -1){
                first_idx = count;
            }
            if(last_idx != -1){
                if(count - last_idx < min){
                    min = count - last_idx;
                }
            }
            last_idx = count;

        }
        prev = cur;
        cur = cur->next;
        count++;
    }
    //printf("%d %d", min, last_idx - first_idx);
    if(first_idx == -1 || last_idx - first_idx == 0){
        answer[0] = -1;
        answer[1] = -1;
        return answer;
    }
    answer[0] = min;
    answer[1] = last_idx - first_idx;
    return answer;
}
