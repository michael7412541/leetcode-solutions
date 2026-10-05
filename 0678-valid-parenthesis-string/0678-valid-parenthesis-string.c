bool checkValidString(char* s) {
    int max_op = 0;
    int min_op = 0;
    int size = strlen(s);
    for(int i = 0; i < size; i++){
        if(s[i] == '('){
            max_op++;
            min_op++;
        }   
        else if(s[i] == ')'){
            max_op--;
            min_op--;
        }
        else{
            max_op++;
            min_op--;
        }
        if(max_op < 0) return false;
        if(min_op < 0) min_op = 0;
    }
    return min_op == 0;
}