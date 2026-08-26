bool compare(char *s, int left, int right, int ans_L, int ans_R){
    if(right - left > ans_R - ans_L)
        return false;
    else if(right - left < ans_R - ans_L)
        return true;
    else{
        for(int i = 0; i <= right - left; i++){
            if(s[i + left] < s[i + ans_L])
                return true;
            else if(s[i + left] > s[i + ans_L])
                return false;
        }
        return true;
    }
}
char* shortestBeautifulSubstring(char* s, int k) {
    int size = strlen(s);
    int count = 0, right = 0, left = 0, ans_L = 0, ans_R = 0, init = 0; 
    for(right = 0; right < size; right++){
        if(s[right] == '1')
            count++;
        while(left < right && s[left] == '0'){
            left++;
        }
        while(count > k){
            if(s[left++] == '1')
                count--;
        }
        while(left < right && s[left] == '0'){
            left++;
        }

        if(count == k){
            if(init == 0){
                ans_L = left;
                ans_R = right;
                init = 1;
            }
            
            if(compare(s, left, right, ans_L, ans_R)){

               // printf("%d %d, %d %d", left, right, ans_L, ans_R);
                ans_L = left;
                ans_R = right;
            }
            
        }
    }
    if(init == 0)
        return "";
    char *answer = malloc(sizeof(int)*(ans_R - ans_L + 2));
    for(int i = ans_L; i <= ans_R; i++){
        answer[i-ans_L] = s[i];
    }
    answer[ans_R - ans_L + 1] = '\0';
    return answer;
}
