


typedef struct {
    int *stack;
    int *price;
    int top;
    int capacity;
    int count;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner *stock = malloc(sizeof(StockSpanner));
    stock->top = -1;
    stock->capacity = 10000;
    stock->count = 0;
    stock->stack = malloc(sizeof(int) * stock->capacity);
    stock->price = malloc(sizeof(int) * stock->capacity);

    return stock; 
}

int stockSpannerNext(StockSpanner* obj, int price) {
    obj->price[obj->count] = price;

    int answer = 1;

    while(obj->top >= 0 && obj->price[obj->stack[obj->top]] <= price){
        obj->top--;
    }

    if(obj->top == -1) 
        answer = obj->count + 1;
    else
        answer = obj->count - obj->stack[obj->top]; 
    
    obj->stack[++obj->top] = obj->count++;
    
    return answer;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->stack);
    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/
