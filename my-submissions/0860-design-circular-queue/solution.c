


typedef struct {
    int size;
    int head;
    int tail;
    int *data;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *q;
    q = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    q->size = k;
    q->data = (int*)malloc(sizeof(int)*k);
    memset(q->data, 0, k*sizeof(int));
    q->head = -1;
    q->tail = -1;
    return q;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->head == -1)
        return true;
    else
        return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    /*if((obj->tail - obj->head == obj->size - 1) || (obj->tail - obj->head == -1))
        return true;
    else
        return false;*/
    return ( (obj->tail + 1) % obj->size ) == obj->head;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))
        return false;
    else {
        if(obj->head == -1)
        {
            obj->head = 0;
            obj->data[0] = value;
            obj->tail = 0;
        }
        else
        {
            obj->tail = (obj->tail + 1) % obj->size;
            obj->data[obj->tail] = value;
        }
        
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return false;
    /*else {
        obj->head = (obj->head + 1) % obj->size;
        return true;
    }*/



    if (obj->head == obj->tail) {
        // 只剩一個元素
        obj->head = -1;
        obj->tail = -1;
    } else {
        obj->head = (obj->head + 1) % obj->size;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;
    else {
        int temp = obj->data[obj->head];
        //obj->head = (obj->head + 1) % obj->size;
        return temp;
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
     if(myCircularQueueIsEmpty(obj))
        return -1;
    else {
        int temp = obj->data[obj->tail];
        //obj->tail = (obj->tail - 1) % obj->size;
        return temp;
    }
}



void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
