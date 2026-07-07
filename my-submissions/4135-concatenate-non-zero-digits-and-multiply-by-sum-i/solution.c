long long sumAndMultiply(int n) {
    long long x = 0, sum = 0, a = 0, sum1 = 0, b = 0, y = 0;
    while(n > 0){
        a = n % 10;
        if(a == 0){
            //
        }
        else{
            x = x * 10 + a;
            sum += a;
        }
        n = n/10;
    }
    while(x > 0){
        b = x % 10;
        sum1 = sum1 * 10 + b; 
        x = x / 10;
    }
    //printf("sum = %d, x = %d", sum ,x);
    return sum * sum1;
}
