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