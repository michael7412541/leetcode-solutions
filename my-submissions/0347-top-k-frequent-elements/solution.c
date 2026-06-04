/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct BucketNode {
    int val;
    struct BucketNode *next;
};
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int hash[20001] = {0};
    int *answer = malloc(sizeof(int) * 100000);
    int i = 0, offset = 10000, count = 0;
    struct BucketNode *freq[numsSize+1], *temp;
    for(i = 0; i <= numsSize; i++){
        if(i < numsSize)
            hash[nums[i] + offset]++;
        freq[i] = NULL;
    }
    for(i = 0; i < 20001; i++){
        if(hash[i] > 0){
            if(freq[hash[i]] == NULL){
                freq[hash[i]] = malloc(sizeof(struct BucketNode));
                freq[hash[i]]->val = i;
                freq[hash[i]]->next = NULL;
            }
            else{
                struct BucketNode *new = malloc(sizeof(struct BucketNode));
                new->val = i;
                new->next = freq[hash[i]];
                freq[hash[i]] = new;
            }
        }
    }

    *returnSize = k;
    for(i = numsSize; i >= 0; i--){
        temp = freq[i];
        while(temp != NULL){
            answer[count++] = temp->val - offset;

            if(count == k)
                return answer;
            printf("%d ", temp->val);
            temp = temp->next;
        }
        
    }
    return answer;

}
