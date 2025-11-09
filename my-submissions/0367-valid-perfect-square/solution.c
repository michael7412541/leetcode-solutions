bool isPerfectSquare(int num){
    int left = 0, right = num/2;
    long long mid = 0;
    if(num == 1)
        return true;
    while(left <= right){
        mid = left + (right - left)/2;
        printf("L = %d, R = %d, M = %d\n", left, right, mid);
        if(mid * mid == num)
            return true;
        else if(mid * mid > num)
            right = mid - 1;
        else
            left = mid + 1;
    }
    
    return false;
}
