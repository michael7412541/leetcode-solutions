/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int temp = 0, count = 0, *answer = malloc(sizeof(int) * 1000000);
    *returnSize = n + 1;
    for(int i = 0; i <= n; i++){
        temp = i;
        count = 0;
        while(temp > 0){
            count += temp & 1;
            temp = temp >> 1;
        }
        answer[i] = count;
    }
    return answer;
}
