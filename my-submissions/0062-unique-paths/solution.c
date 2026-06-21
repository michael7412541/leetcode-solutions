int helper(int m, int n, int memory[101][101]){
    
    if(m == 0 && n == 0)
        memory[m][n] = 1;
    else if(m == 0 || n == 0)
        memory[m][n] = 1;
    else if(memory[m][n] != -1){
        return memory[m][n];}
    else
        memory[m][n] = helper(m - 1, n, memory) + helper(m, n - 1, memory);


    return memory[m][n];
}
int uniquePaths(int m, int n) {
    int memory[101][101];


    memset(memory, -1, sizeof(int) * 101 * 101);
    int answer = helper(m - 1, n - 1, memory);

    return answer;
}
