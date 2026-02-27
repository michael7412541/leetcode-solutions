

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){
    int sum = 0, lines = 1, i = 0;
    int *answer = (int*)malloc(sizeof(int)*2);
    while(s[i] != '\0'){
        
        if(sum + widths[s[i] - 'a'] > 100){
            sum = widths[s[i] - 'a'];
            lines++;
        }
        else{
            sum = sum + widths[s[i] - 'a'];
        }

        i++;
    }
    *returnSize = 2;

    answer[0] = lines;
    answer[1] = sum;
    return answer;
}
