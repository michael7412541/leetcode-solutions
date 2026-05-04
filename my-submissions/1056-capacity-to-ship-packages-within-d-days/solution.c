bool check_valid(int key, int* weights, int weightsSize, int days){
    int count = 1, sum = 0;
    printf("key = %d\n", key);
    for(int i = 0; i < weightsSize; i++){
        if(sum + weights[i] > key){
            sum = weights[i];
            count++;
        }
        else{
            sum += weights[i];
        }
    }
    printf("count = %d\n", count);
    return count <= days;

} 
int shipWithinDays(int* weights, int weightsSize, int days) {
    int sum = 0, max = INT_MIN;
    for(int i = 0; i < weightsSize; i++){
        sum += weights[i];
        if(max < weights[i])
            max = weights[i];
    }
    int mid, left = sum / days, right = sum;
    while(left < right){
        mid = left + (right- left)/2;
        if(check_valid(mid, weights, weightsSize, days)){
            right = mid;
        }
        else
            left = mid + 1;
    } 
    return left > max ? left : max;
}
