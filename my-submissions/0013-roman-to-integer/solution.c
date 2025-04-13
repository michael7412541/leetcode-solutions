int romanToInt(char* s) {
    int answer = 0;
    int i = 0;
    int diff = 0;
    int diff_old = 2222;
    for(i = 0; i < strlen(s) ; i++)
    {
        if(s[i] == 'I')
        {
            diff = 1;
        }
        else if(s[i] == 'V')
        {
            diff = 5;    
        }
        else if(s[i] == 'X')
        {
            diff = 10; 
        }
        else if(s[i] == 'L')
        {
            diff = 50;    
        }
        else if(s[i] == 'C')
        {
            diff = 100;    
        }
        else if(s[i] == 'D')
        {
            diff = 500;    
        }
        else if(s[i] == 'M')
        {
            diff = 1000;    
        }

        answer = answer + diff;
        
        if(i >= 1)
            if(diff > diff_old)
                answer = answer - 2*diff_old;
        diff_old = diff;
    }
    return answer;
}
