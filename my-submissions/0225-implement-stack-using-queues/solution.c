


typedef struct {
    int head1;
    int head2;
    int tail1;
    int tail2;
    int *queue1;
    int *queue2;
} MyStack;


MyStack* myStackCreate() {
    MyStack *stack = malloc(sizeof(MyStack));//struct MyStack *stack = (MyStack*)malloc(sizeof(MyStack));
    stack->head1 = -1;
    stack->head2 = -1;
    stack->tail1 = -1;
    stack->tail2 = -1;
    stack->queue1 = (int*)malloc(sizeof(int)*100);
    stack->queue2 = (int*)malloc(sizeof(int)*100);
    return stack;
}

void enqueue(int *queue, int *head, int *tail, int value) {
    if(*head == -1) {//empty
        *head = 0;
        *tail = 0;
        queue[*head] = value;
    }
    else {
        (*tail)++;
        queue[*tail] = value;
    }
}

int dequeue(int *queue, int *head, int *tail) {
    if(*head == -1) {
        return -1;
    }
    else {
        int temp = queue[*head];
        (*head)++;
        //if(*head == *tail) {
        if(*head > *tail) {
            *head = -1;
            *tail = -1;
        }
        return temp;
    }
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj->queue1, &obj->head1, &obj->tail1, x);
}

int myStackPop(MyStack* obj) {
    int i = 0, *temp, value, len = obj->tail1 - obj->head1 + 1;//*+1
    if(obj->head2 == -1)
    {    
        for(i = 0; i < len - 1; i++){
            int temp = dequeue(obj->queue1, &obj->head1, &obj->tail1);
            enqueue(obj->queue2, &obj->head2, &obj->tail2, temp);
        }
        value = dequeue(obj->queue1, &obj->head1, &obj->tail1);
        temp = obj->queue1;
        obj->queue1 = obj->queue2;
        obj->queue2 = temp;
        
        int htmp = obj->head1, ttmp = obj->tail1;
        obj->head1 = obj->head2;
        obj->tail1 = obj->tail2;
        obj->head2 = htmp;
        obj->tail2 = ttmp;
        return value;
    }
    else {
        return dequeue(obj->queue1, &obj->head1, &obj->tail1);
    }
    
}

int myStackTop(MyStack* obj) {
    if(obj->tail1 == -1)
        return obj->queue2[obj->tail2];
    else
        return obj->queue1[obj->tail1];
}

bool myStackEmpty(MyStack* obj) {
    if(obj->head1 == -1 && obj->head2 == -1)
        return true;
    else
        return false;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/


/*
改動重點
Pop：

判斷 queue2 是否空

若空，就從 queue1 搬 n-1 個到 queue2，剩下最後一個直接彈出

若不空，就直接從 queue2 彈出（因為它已經是 stack 頂端序列）

Top：

判斷哪個 queue 是當前活躍的，直接從那個 queue 的尾端取值

這樣改動量很小，幾乎保留了你原本的框架與函式介面，也能保證 LIFO 行為正確。*/
