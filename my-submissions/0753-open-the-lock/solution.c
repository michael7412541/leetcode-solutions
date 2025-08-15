
#define MAX_STATE 10000
int state2int(const char *state) {
    int temp;
    temp = (state[0] - '0') * 1000 + (state[1] - '0') * 100 +(state[2] - '0') * 10 + (state[3] - '0');
    return temp;
}

void int2state(int num, char *state) {
    state[0] = '0' + num/1000;
    state[1] = '0' + (num/100) % 10;
    state[2] = '0' + (num/10) % 10;
    state[3] = '0' + num % 10;
    state[4] = '\0';
}

void getNeighbors(int curr, int *neighbors, int *count) {
    char state[5];
    int2state(curr, state);
    *count = 0;
    
    for(int i = 0; i < 4; i++) {
        char orig = state[i];
        
        state[i] = (orig == '9') ? '0' : orig + 1;
        neighbors[(*count)++] = state2int(state);
        
        state[i] = (orig == '0') ? '9' : orig - 1;
        neighbors[(*count)++] = state2int(state);
        
        state[i] = orig;
    }
}

int openLock(char** deadends, int deadendsSize, char* target) {
    bool visited[MAX_STATE] = {false};
    bool dead[MAX_STATE] = {false};
    
    for(int i = 0; i < deadendsSize; i++) {
        dead[state2int(deadends[i])] = true;
    }
    
    int targetNum = state2int(target);
    int start = state2int("0000");
    
    if(dead[start]) return -1;
    
    int *queue = (int*)malloc(sizeof(int) * MAX_STATE);
    int head = 0, tail = 0;
    
    queue[tail++] = start;
    visited[start] = true;
    
    int steps= 0;
    
    while(head <tail) {
        int size = tail - head;
        
        for(int i = 0; i < size; i++) {
            int curr = queue[head++];
            
            if(curr == targetNum) {
                free(queue);
                return steps;
            }
            
            int neighbors[8];
            int count;
            getNeighbors(curr, neighbors, &count);
            
            for(int j = 0; j < count; j++) {
                int next = neighbors[j];
                if(!visited[next] && !dead[next]) {
                    visited[next] = true;
                    queue[tail++] = next;
                }
            }
        }
        steps++;
    }
    free(queue);
    return -1;
}
