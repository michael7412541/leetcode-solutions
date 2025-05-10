void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = * b;
    *b = temp;
}
void reverse(char *s, int left, int right)
{
    while(left < right)
    {
        //if(s[left] == ' ')
        //{
            
        //}
        //else
        //{
            swap(&s[left], &s[right]);
            left++;
            right--;
        //}
    }
        
}
int removespace(char *s)
{
    int i = 0, j = 0;
    
    while(s[i] == ' ')//開頭空白
        i++;
    int n = strlen(s);
    while(i < n)
    {
        if(s[i] != ' ')
        {
            s[j] = s[i];
            j++;
            i++;
        }
        else
        {
            s[j] = ' ';
            j++;
            while(s[i] == ' ')
            {
                    i++;
            }
        }        
    }
    if (j > 0 && s[j - 1] == ' ') j--;
    s[j] = '\0';
    return j;
    
}

char* reverseWords(char* s) {
    int len;
    int i = 0, start = 0, end = 0;
    len = removespace(s);
    printf(" %d", len);
    reverse(s, 0, len - 1);
    
    for(i = 0; i < len; i++)
    {
        if(s[i] == ' ')
        {
            if(i > 0){
                end = i - 1;
                reverse(s, start, end);
                start = i + 1;
            }
        }
        else if(i == len - 1)
        {
            reverse(s, start, i);
        }
    }
    
    return s;

}
