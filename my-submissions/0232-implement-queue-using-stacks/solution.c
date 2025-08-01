


typedef struct {
    int *stack_in;
    int *stack_out;
    int top_in;
    int top_out;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stack_in = (int*)malloc(sizeof(int)*100);
    queue->stack_out = (int*)malloc(sizeof(int)*100);
    queue->top_in = -1;
    queue->top_out = -1;
    return queue;
}
bool myQueueEmpty(MyQueue* obj) {
    if(obj->top_in == -1 && obj->top_out == -1)
        return true;
    else
        return false;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack_in[++obj->top_in] = x;
}

int myQueuePop(MyQueue* obj) {
    if(obj->top_out == -1) {
        int i = 0;
        for(i = obj->top_in;i >= 0 ;i--) {
            obj->stack_out[i] = obj->stack_in[obj->top_in - i];
        }
        obj->top_out = obj->top_in;
        obj->top_in = -1;
    }
    
    return obj->stack_out[obj->top_out--];
}

int myQueuePeek(MyQueue* obj) {
    if(obj->top_out == -1) {
        int i = 0;
        for(i = obj->top_in;i >= 0 ;i--) {
            obj->stack_out[i] = obj->stack_in[obj->top_in - i];
        }
        obj->top_out = obj->top_in;
        obj->top_in = -1;
    }
    return obj->stack_out[obj->top_out];
}



void myQueueFree(MyQueue* obj) {
    free(obj->stack_in);
    free(obj->stack_out);
    free(obj);
}

//只有在 stack_out 是空的時候才會從 stack_in 把資料倒過去。

//這種方式模擬了 queue 的先進先出（FIFO）行為。

//這就是為什麼我們要 lazy transfer（延遲轉移），來保持效率。



/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
