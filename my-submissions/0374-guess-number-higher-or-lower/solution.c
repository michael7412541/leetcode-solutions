/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);
int guessNumber(int n){
    int left = 1, right = n, middle = 0;
    if(n == 0 || n == 1)
        return n;
    while(left <= right){
        middle = left + (right - left)/2;
        if(guess(middle) == -1){
            right = middle - 1;
        }
        else if(guess(middle) == 1){
            left = middle + 1;
        }
        else
            return middle;
    }
    return n;
}
