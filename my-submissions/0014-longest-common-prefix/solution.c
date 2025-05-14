char* longestCommonPrefix(char** strs, int strsSize) {
    //先找到最短的
    
    int target = 0,i = 0,k = 0, limit = 200, n1, n2;
    
    //都拿第0個當作target，開始從第k個來比對
    for(k = 1; k < strsSize; k++)
    {
        n1 = strlen(strs[0]);
        n2 = strlen(strs[k]);
        for(i = 0; i < n1 && i < n2 && i < limit; i++)
        {
            if(strs[0][i] != strs[k][i])
                break;
        }
        //printf("%d ", limit);
        limit = i;
    }
    
    if(limit == 0)
        return "";
    else
    {
        char *answer = (char*)malloc((limit+1)*sizeof(char));
        strncpy(answer,strs[0],limit);
        answer[limit] = '\0';
        return answer;
    }
        
}
