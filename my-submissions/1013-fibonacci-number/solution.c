int calculate(int i, int *hash) {
    
    if(i <= 1) {
        hash[i] = i;
        return i;
    }
    else if(hash[i] != 0)
        return hash[i];
    else {
        hash[i] = calculate(i - 1, hash) + calculate(i - 2, hash); 
        return hash[i];
        //return calculate(i - 1, hash) + calculate(i - 2, hash); 
    }
}

int fib(int n){
    int *hash = (int*)calloc(sizeof(int), 31);
    
    return calculate(n, hash);
}
