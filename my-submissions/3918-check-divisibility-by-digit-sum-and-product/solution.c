bool checkDivisibility(int n) {
    
    int sum = 0, product = 1, digit = 0, num = n;
    while(num > 0){
        digit = num % 10;
        sum += digit;
        product *= digit;
        num = num/10;
    }
    int answer = n % (sum + product)  ; 
    return (answer == 0) ;
}
