int cal_hash(int *hash, int size){
    int count = 0;
    for(int i = 0; i < size; i++)
        if(hash[i] != 0)
            count++;
    
    return count;
}
int totalFruit(int* fruits, int fruitsSize) {
    int left = 0, right, answer = 0, category = 0;
    int *hash = calloc(fruitsSize, sizeof(int));
    for(right = 0; right < fruitsSize; right++){
        if(hash[fruits[right]] == 0)
            category++;
        hash[fruits[right]]++;

        while(category > 2 && left <= right){
            hash[fruits[left]]--;
            if(hash[fruits[left]] == 0){
                category--;
            }
            
            left++;
        }
        if(right - left + 1 > answer)
            answer = right - left + 1;
    }
    return answer;
}//找出只包含兩種數字的最長subarray
