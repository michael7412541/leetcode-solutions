/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i = 0, carry = 0;
    while(i < digitsSize){
        if(digits[i] != 9)
            break;
        i++;
    }
    if(i == digitsSize){//全部都是9才會需要多一個位元
        *returnSize = digitsSize + 1;
        int *answer = malloc(sizeof(int) * (*returnSize));
        answer[0] = 1;
        for(i = 1; i < (*returnSize); i++)
            answer[i] = 0;
        return answer;
    }
    else{
        *returnSize = digitsSize;
        int *answer = malloc(sizeof(int) * (*returnSize));
        
        for(i = digitsSize - 1; i >= 0; i--){
            if(i == digitsSize - 1){
                answer[i] = (digits[i] + 1) % 10;
                carry = (digits[i] + 1) / 10;
            }
            else{
                answer[i] = (digits[i] + carry) % 10;
                carry = (digits[i] + carry) / 10;
            }
        }
        return answer;
    }
}
