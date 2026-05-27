int numberOfSpecialChars(char* word) {
    int hash[26] = {0}, answer = 0, size = strlen(word);
    for(int i = 0; i < size; i++){
        if(word[i] >= 'a' && word[i] <= 'z'){
            if(hash[word[i] - 'a'] == -1 || hash[word[i] - 'a'] == 2)
                hash[word[i] - 'a'] = -1;
            else{
                hash[word[i] - 'a'] = 1;
            }

                
        }
        else{
            if(hash[word[i] - 'A'] == 1){
                hash[word[i] - 'A'] = 2;
            }
            else if(hash[word[i] - 'A'] == 0)
                hash[word[i] - 'A'] = -1;
        }
    }

    for(int i = 0; i < 26; i++)
    {
        if(hash[i] == 2)
            answer++;
    }
    return answer;
}
