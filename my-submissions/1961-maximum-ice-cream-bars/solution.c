int maxIceCream(int* costs, int costsSize, int coins) {
    int hash[100001], sum = 0, count = 0;
    memset(hash, 0, sizeof(int) * 100001);
    for(int i = 0; i < costsSize; i++){
        hash[costs[i]]++;
    }
    while(coins > 0 && count < 100001){
        if(hash[count] != 0){

            if(coins/count >= hash[count]){
                sum += hash[count];
                coins -= hash[count] * count;
            }  
            else{
                sum += coins/count;
                break;

            }
        }
        count++;
    }

    return sum;
}
