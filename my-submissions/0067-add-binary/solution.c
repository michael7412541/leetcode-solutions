char* addBinary(char* a, char* b) {
    if(a == NULL || b == NULL)
        return NULL;
    
    int len_a = strlen(a);
    int len_b = strlen(b);
    int i = 0, j = 0, k = 0, carry = 0;
    int c1, c2, c3, temp = 0;
    char* answer;
    int max_len = (len_a > len_b ? len_a : len_b);
    answer = (char*)malloc((max_len + 2) * sizeof(char)); // +1 for carry, +1 for '\0'
    answer[max_len + 1] = '\0'; // Null terminator
    k = max_len;
    i = len_a - 1;
    j = len_b - 1;

    while(j >= 0 || i >= 0)
    {
        c1 = (i >= 0 && a[i] == '1')? 1 : 0;
        c2 = (j >= 0 && b[j] == '1')? 1 : 0;
        c3 = (carry == 1)? 1 : 0;
        temp = c1 + c2 + c3;
        if(temp == 1)
        {
            carry = 0;
            answer[k] = '1';
        }
        else if(temp == 2)
        {
            carry = 1;
            answer[k] = '0';
        }
        else if(temp == 3)
        {
            carry = 1;
            answer[k] = '1';
        }
        else//temp ==0
        {
            carry = 0;
            answer[k] = '0';
        }
        
        k--;
        j--;
        i--;
    }
    
    
    if(carry == 1)
    {
        answer[k] = '1';
        return &answer[k];
    }
    else
        return &answer[k+1];
    
}
