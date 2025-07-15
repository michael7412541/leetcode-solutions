


typedef struct {
    int top;
    int mintop;
    int data[30000];
    int minstack[30000];
} MinStack;


MinStack* minStackCreate() {
    MinStack *stack = (MinStack*)malloc(sizeof(MinStack));
    stack->top = -1;
    stack->mintop = -1;
    return stack;
}
bool isEmpty(MinStack* obj) {
    if(obj->top == -1)
        return true;
    else
        return false;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->data[obj->top] = val;
    //if(val <= obj->minstack[obj->mintop])
    
    if(obj->mintop == -1 ||val <= obj->minstack[obj->mintop])
    {
        obj->mintop++;
        obj->minstack[obj->mintop] = val;
    }
}

void minStackPop(MinStack* obj) {
    if(isEmpty(obj))
        return ;
    else {
        if(obj->data[obj->top] == obj->minstack[obj->mintop])
        {
            obj->mintop--;
        }
        obj->top--;
    }
}        

int minStackTop(MinStack* obj) {
    if(isEmpty(obj))
        return 0;
    else
        return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    if(isEmpty(obj))
        return 0;
    else
        return obj->minstack[obj->mintop];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
