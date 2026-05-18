bool check(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c  <= '9');
}
bool isPalindrome(char* s) {
    
    int pt1 = 0, pt2 = strlen(s) - 1, diff = abs('A' - 'a');
    while(pt1 < pt2){
        
        while(check(s[pt1]) == false && pt1 < pt2){
            pt1++;
            //printf("pt1: %d, pt2: %d\n", pt1, pt2);
        }
        while(check(s[pt2]) == false && pt1 < pt2){
            pt2--;
            //printf("pt1: %d, pt2: %d\n", pt1, pt2);
        }
        printf("pt1: %d, pt2: %d\n", pt1, pt2);
        if(tolower(s[pt1]) != tolower(s[pt2]))
            return false;
        
        pt1++;
        pt2--;
    
    }
    return true;
}
