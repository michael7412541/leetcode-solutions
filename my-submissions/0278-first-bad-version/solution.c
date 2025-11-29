// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int version);
int firstBadVersion(int n) {
    int left = 1, right = n, middle = 0;
    while(left < right){
        middle = left + (right - left)/2;
        if(isBadVersion(middle) == 1){
            right = middle;
        }
        else{
            left = middle + 1;
        }
    }
    if(left == right)
        return left;
    else
        return 0;
}
