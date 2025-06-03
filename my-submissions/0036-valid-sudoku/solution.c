int hash(char c)
{
    c = c - '1';
    if(c >= 0 && c <= 8)
        return (int)c;
    else
        return -1;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int i = 0, j = 0, idx = 0;
    int *hashmap = calloc(9, sizeof(int));
    for(i = 0; i < 9; i++)
    {
        memset(hashmap, 0, 9*sizeof(int));
        for(j = 0; j < 9; j++)
        {
            idx = hash(board[i][j]);
            if(idx >= 0)
            {
                hashmap[idx]++;
                if(hashmap[idx] > 1)
                    return false;
            }
        }
    }
    for(i = 0; i < 9; i++)
    {
         memset(hashmap, 0, 9*sizeof(int));
        for(j = 0; j < 9; j++)
        {
            idx = hash(board[j][i]);
            if(idx >= 0)
            {
                hashmap[idx]++;
                if(hashmap[idx] > 1)
                    return false;
            }
        }
    }
    int h = 0, v = 0;
    for(h = 0; h < 9; h+=3)
    {
        for(v = 0; v < 9; v+=3)
        {
             memset(hashmap, 0, 9*sizeof(int));
            for(i = h; i < h+3; i++)
            {
               for(j = v; j < v+3; j++)
                {
                    idx = hash(board[i][j]);
                    if(idx >= 0)
                    {
                      hashmap[idx]++;
                      if(hashmap[idx] > 1)
                            return false;
                    }
                } 
            }
        }
    }
    return true;
    
}
