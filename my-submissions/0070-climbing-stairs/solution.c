int calculate(int n, int *hash) {
    if(hash[n] != 0) {
        return hash[n];
    }
    else if(n == 1 || n == 2) {
        hash[n] = n;
        return hash[n];
    }
    else {
        hash[n] = calculate(n - 1, hash) + calculate(n - 2, hash);
        return hash[n];
    }
}
int climbStairs(int n) {
    int *hash = (int*)calloc(46, sizeof(int));
    int result = calculate(n, hash);
    free(hash);
    return result;
    /*int sum = 0, x = 0, y = 0;
    long long res = 1;
    for(y = 0; y <= n/2; y++) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        
        x = n - 2* y;
        
        if(x == 0 || y == 0)
            sum += 1;
        else {
            res = 1;
            //calculate Cx+y y
            for (int i = 1; i <= x; i++) {
                    res = res * (y + i) / i;
            }
            sum += res;
        }
    }
    return sum;*/
}
