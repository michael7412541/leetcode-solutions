

int reverse(int x){
    int temp = 0;
    if(x >= INT_MAX || x < INT_MIN)
        return 0;
    while(x){
        printf("%d ", x % 10);
        if(temp > INT_MAX/10 || temp < INT_MIN/10)
            return 0;
        temp = temp * 10 + x % 10;
        x = x/10;
        
        printf("%d\n", temp);
        
    }
    return temp;
}
