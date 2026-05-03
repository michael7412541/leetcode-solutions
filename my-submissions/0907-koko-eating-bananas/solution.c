bool check_valid(int key, int *piles, int pilesSize, int h){
    int time = 0;
    for(int i = 0; i < pilesSize; i++){
        int temp = piles[i]/key;
        if(piles[i] > temp * key)
            time += temp + 1;
        else
            time += temp;
    }
    if(time > h)
        return false;
    else
        return true;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    if(pilesSize == 0)
        return 0;
    if(pilesSize == 1)
        return piles[0] % h ? piles[0]/h + 1 : piles[0]/h;
    int left = 0, right = 0, max = INT_MIN;
    long long sum = 0;
    for(int i = 0; i < pilesSize; i++){
        sum += piles[i];
        if(piles[i] > max)
            max = piles[i];

    }
    left = sum/h;
    right = max;
    int mid;
    while(left < right){
        mid = left + (right - left)/2;
        if(check_valid(mid, piles, pilesSize, h)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }

    return left;
    
}
