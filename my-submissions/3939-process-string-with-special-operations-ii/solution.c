void swap(char *a, char *b){
    char temp= *a;
    *a = *b;
    *b = temp;
}

void print_status(char *string, int pos){
    for(int i = 0; i < pos + 1; i++)
     printf("%c", string[i]);
}

char processStr(char* s, long long k) {
    
    long long size = strlen(s), pos = -1, length = size;
    char *string = malloc(sizeof(char) * size);
    long long history_pos[size];
    //string長度為pos+1
    if(k > pow(2, size))
        return '.';
    for(int i = 0; i < size; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            ++pos;
        }
        else if(s[i] == '%'){
            //
        }
        else if(s[i] == '*'){
            if(pos + 1 > 0)
                pos--;
        }
        else if(s[i] == '#'){
            pos = pos * 2 + 1;
        }
        else
            return 0;
        history_pos[i] = pos;
        //printf("\ni = %d pos = %d", i, pos);
        //print_status(string, pos);
    }


    if(k > pos)
        return '.';
    
    for(int i = size - 1; i >= 0; i--){
        long long cur_pos = history_pos[i];
        long long prev_pos = i > 0 ? history_pos[i - 1] : -1;
        if(s[i] >= 'a' && s[i] <= 'z'){
            if(cur_pos == k)
                return s[i];
        }
        else if(s[i] == '%'){
            if(cur_pos >= 0)
                k = cur_pos - k;
        }
        else if(s[i] == '*'){
            
        }
        else if(s[i] == '#'){
            if(k > prev_pos)
                k -= (prev_pos + 1);
        }
        else
            return 0;
        
    }
    
    return '.';
}
