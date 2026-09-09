long long countCommas(long long n) {
    //0~999: 0
    //1,000~999,999: 998 999
    //1,000,000~999,999,999: 998 999 999 * 2
    //1,000,000,000~999,999,999,999: 999 000 000 000 * 3
    long long s = 0;
    if(n < s)
        return 0;
    long long answer = 0;
    for(int i = 0; i < 6; i++){
        s += 999 * pow(1000, i);
        //printf("i = %d, s = %ld, p = %ld\n", i, s, pow(1000, i));
        if(n >= s){
            answer += (s - pow(1000, i) + 1) * i;
        }
        else{
            answer += (n - pow(1000, i) + 1) * i;
            return answer;
        }
    }
    return answer;
}
//1,004,590 => 999,000 + 
