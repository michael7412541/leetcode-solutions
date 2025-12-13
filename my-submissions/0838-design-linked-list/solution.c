


typedef struct MyLinkedList{
    int val;
    struct MyLinkedList *next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *list = malloc(sizeof(MyLinkedList));
    list->val = 0;//dummy value
    list->next = NULL;
    return list;
}


//obj === obj->next === obj->next->next
//             0          1               2
int myLinkedListGet(MyLinkedList* obj, int index) {
    struct MyLinkedList *cur = obj->next;
    while(cur != NULL && index > 0){
        cur = cur ->next;
        index--;
    }
    if(index != 0 || cur == NULL)
        return -1;
    return cur->val;
    
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct MyLinkedList *newhead = malloc(sizeof(MyLinkedList));
    newhead->val = val;
    newhead->next = obj->next;
    obj->next = newhead;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct MyLinkedList *newtail = malloc(sizeof(MyLinkedList));
    struct MyLinkedList *cur = obj;
    
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = newtail;
    newtail->val = val;
    newtail->next = NULL;
    
}

/*void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    struct MyLinkedList *cur = obj, *prev = obj;
    struct MyLinkedList *newNode = malloc(sizeof(MyLinkedList));
    newNode->val = val;
    while(cur != NULL && index > 0){
        prev = cur;
        cur = cur ->next;
        index--;
    }
    
    if(index > 0){
        free(newNode);
        return;
    }
    newNode->next = prev->next;//原本是cur
    prev->next = newNode;

}*/
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    // 1. 處理負索引
    if (index < 0) return;

    struct MyLinkedList *prev = obj; // prev 總是作為新節點的前一個節點
    
    // 遍歷到目標索引的前一個節點
    // 從虛擬頭節點 (index -1) 開始，遍歷 index 次，最終停在 index - 1 的位置
    while (prev != NULL && index > 0) {
        prev = prev->next;
        index--;
    }
    
    // 2. 邊界檢查
    // 如果 prev == NULL，表示 index 超出了鏈表長度，或者 index 太大導致 prev 走到了鏈表末尾的 NULL
    // 且 index 仍 > 0 (表示 index > length + 1)
    if (prev == NULL) { 
        return;
    }

    // 3. 插入節點
    struct MyLinkedList *newNode = malloc(sizeof(MyLinkedList));
    newNode->val = val;
    
    newNode->next = prev->next; // 新節點指向 prev 後面的節點
    prev->next = newNode;       // prev 指向新節點
}

/*void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    struct MyLinkedList *cur = obj, *prev = obj;
    //struct MyLinkedList *newNode = malloc(sizeof(MyLinkedList));
    while(cur != NULL && index > 0){
        prev = cur;
        cur = cur ->next;
        index--;
    }
    
    if(index > 0 || cur == NULL){
        return;
    }
    prev->next = cur->next;
    free(cur);
    
}*/
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    // 從虛擬頭節點 obj 開始，prev 將停在要刪除節點的前一個
    struct MyLinkedList *prev = obj; 
    
    // 遍歷到 index 的前一個位置 (index - 1)
    // 如果 index=0，循環不執行，prev 仍是 obj
    while(prev->next != NULL && index > 0){
        prev = prev->next;
        index--;
    }
    
    // 遍歷結束時：
    // 如果 index > 0，說明 index 超出長度，或
    // 如果 prev->next == NULL 且 index == 0 (說明鏈表為空，或刪除的 index 太大)
    
    // 修正判斷邏輯：
    // 只需要檢查 prev 是否在合法範圍內，且 prev 的下一個節點是否存在
    if (index > 0 || prev->next == NULL) {
        return; // index 太大，或無效操作
    }
    
    // 刪除操作：
    struct MyLinkedList *to_delete = prev->next;
    
    // 1. 繞過節點
    prev->next = to_delete->next; 
    
    // 2. 釋放節點
    free(to_delete);
}

void myLinkedListFree(MyLinkedList* obj) {
    struct MyLinkedList *prev = obj, *cur = prev->next;
    while(prev != NULL){//cur != NULL
        cur = prev->next;
        free(prev);
        prev = cur;
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
