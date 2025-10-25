int mySqrt(int x) {
    int left = 0, right = x, middle = 0, ans = 0;
    if(x == 0)
        return 0;
    if(x == 1)
        return 1;
    while(left <= right){
        middle = (left + right)/2;
        if((long long)middle * middle > x){
            right = middle - 1;
        }
        else if((long long)middle * middle == x){
            return middle;
        }
        else{
            ans = middle;//*CHATGPT
            left = middle + 1;
        }
    }
    return ans;
}
