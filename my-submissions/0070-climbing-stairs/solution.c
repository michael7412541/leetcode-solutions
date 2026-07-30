int climbStairs(int n) {
    if(n < 3)
        return n;
    int p1, p2, c;
    
    p1 = 1;
    p2 = 2;
    for(int i = 3; i <= n; i++){
        c = p1 + p2;
        p1 = p2;
        p2 = c; 
    }
    return c;
}
