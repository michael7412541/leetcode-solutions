char* removeDuplicateLetters(char* s) {
    int lastPos[26];
    for(int i = 0; i < 26; i++) lastPos[i] = -1;
    char *stack = malloc(sizeof(char) * 27);
    for(int i = 0; s[i] != '\0'; i++){
        lastPos[s[i] - 'a'] = i;
    }
    int visited[26] = {0}, top = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(visited[s[i] - 'a'] > 0) continue;
        
            
        
        while(top > 0 && s[i] < stack[top-1] && i < lastPos[stack[top-1] - 'a']){
            visited[stack[top-1] - 'a']--;
            top--;
        }
        stack[top++] = s[i];
        visited[s[i] - 'a']++;
    }
    stack[top] = '\0';
    return  stack;
}

/*
1. 棧頂索引偏差（Off-by-one）

你的 top 代表的是「棧內元素個數」（以及下一個要填入的空位索引）。

因此，當前的棧頂元素是 stack[top - 1]，而不是 stack[top]。

在 while 迴圈中檢查 stack[top] 讀取的是未初始化的空位，且退出迴圈時會發生越界/未定義行為。

2.  redundant 的 if(top == 0) 推入

代碼中寫了：

C
if(top == 0){
    stack[top++] = s[i];
    visited[s[i] - 'a']++;
}
後面卻又緊接著執行 while 與 stack[top++] = s[i];，導致當棧為空時同一個字元被重複推入兩次（這也是為什麼輸出會多出開頭字母，如 "bbca"）。這個 if 分支應直接移除。

*/
