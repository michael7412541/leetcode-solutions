int strStr(char* haystack, char* needle) {
    if(haystack == NULL || needle == NULL)
    {
        return -1;
    }
    int len_h = strlen(haystack), len_n = strlen(needle);
    int i = 0, j = 0;
    if(len_h < len_n)
        return -1;
    else if(len_h == len_n)
    {
        for(i = 0; i < len_h; i++)
        {
            if(haystack[i] != needle[i])
                    break;
        }
        if(i == len_h)
            return 0;
        else
            return -1;
    }
    
    i = 0;
    
    while(i <= len_h - len_n)
    {
        if(haystack[i] == needle[0])
        {
            if(len_n > 1){
                for(j = i + 1; j < len_n + i; j++)
                {
                    //printf(" haystack = %c, needle = %c \n",haystack[j], needle[j-i]);
                    if(haystack[j] != needle[j-i])
                        break;
                }
            
                if(len_n + i == j)
                    return i;
            }
            else
            {
                return i;
            }
        }
        i++;
    }
    
    return -1;
    
}
