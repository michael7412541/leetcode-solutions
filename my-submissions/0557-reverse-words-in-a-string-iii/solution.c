void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(char *s, int len)
{
    int left = 0, right = len - 1; 
    while(left < right)
    {
        swap(&s[left], &s[right]);
        left++;
        right--;
    }
}

char* reverseWords(char* s) {
    int len = strlen(s);
    int i = 0, start = 0, end = 0;
    while(i <= len && start < len && end <= len)
    {
        if(s[i] == ' ')
        {
            end = i - 1;
            reverse(&s[start],end - start + 1);
            start = i + 1;
        }
        else if(s[i] == '\0')
        {
            end = i;
            reverse(&s[start],end - start);
        }
        i++;
    }
    return s;
}
