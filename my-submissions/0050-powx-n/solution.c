double calculate_pow(double x, long long n) {
    if(n == 0)
        return 1.0;
    double half = calculate_pow(x, n/2);
    if(n % 2 == 0) {
        return half * half;
    }
    else {
        return half * half * x;
    }
}

double myPow(double x, int n) {
    long long N = n;
    if(n == 0)
        return 1;
    if(N < 0) {
        N = -N;
        x = 1/x;
    }
    return calculate_pow(x, N);  
}
