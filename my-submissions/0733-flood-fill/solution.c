/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct Point {
    int x;
    int y;
    int val;
};

struct Point *rim(struct Point *cur, int sel, int** image, int size_x, int size_y){
    int x = 0, y = 0;
    if(sel == 0){
        x = cur->x - 1;
        y = cur->y;
    }
    else if(sel == 1){
        x = cur->x + 1;
        y = cur->y;
    }
    else if(sel == 2){
        x = cur->x;
        y = cur->y + 1;
    }
    else{
        x = cur->x;
        y = cur->y - 1;
    }

    if(x < 0 || y < 0 || x >= size_x || y >= size_y){
        return NULL;
    }
    struct Point *new = malloc(sizeof(struct Point));
    new->x = x;
    new->y = y;
    new->val = image[x][y];
    return new;
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    // 【修正 1】先把 LeetCode 規定的回傳參數設定好，不然直接 return 會崩潰
    *returnSize = imageSize;
    *returnColumnSizes = malloc(sizeof(int) * imageSize); // 修正為 sizeof(int)
    for(int i = 0; i < imageSize; i++){
        (*returnColumnSizes)[i] = imageColSize[i];
    }

    // 【修正 2】如果顏色相同，複製一份 image 給 answer 後直接回傳
    int **answer = malloc(sizeof(int*) * imageSize);
    for(int i = 0; i < imageSize; i++){
        answer[i] = malloc(sizeof(int) * imageColSize[i]);
        for(int j = 0; j < imageColSize[i]; j++){
            answer[i][j] = image[i][j];
        }
    }
    if (image[sr][sc] == color) {
        return answer;
    }

    struct Point *queue[100000], *cur, *up, *down, *left, *right;
    int head = -1, tail = -1;
    
    cur = malloc(sizeof(struct Point));
    cur->x = sr;
    cur->y = sc;
    cur->val = image[sr][sc];
    queue[++tail] = cur;

    int oldcolor = image[sr][sc];
    image[sr][sc] = color;
    answer[sr][sc] = color; // 起點在 answer 矩陣同步染色

    while(head < tail){
        cur = queue[++head];
        up = rim(cur, 0, image, imageSize, imageColSize[0]);
        down = rim(cur, 1, image, imageSize, imageColSize[0]);
        left = rim(cur, 2, image, imageSize, imageColSize[0]);
        right = rim(cur, 3, image, imageSize, imageColSize[0]);
        
        if(up && image[up->x][up->y] == oldcolor) {
            queue[++tail] = up;
            image[up->x][up->y] = color;
            answer[up->x][up->y] = color; // 同步更新 answer
        } else { free(up); }
        
        if(down && image[down->x][down->y] == oldcolor) {
            queue[++tail] = down;
            image[down->x][down->y] = color;
            answer[down->x][down->y] = color; // 同步更新 answer
        } else { free(down); }
        
        if(left && image[left->x][left->y] == oldcolor) {
            queue[++tail] = left;
            image[left->x][left->y] = color;
            answer[left->x][left->y] = color; // 同步更新 answer
        } else { free(left); }
        
        if(right && image[right->x][right->y] == oldcolor) {
            queue[++tail] = right;
            image[right->x][right->y] = color;
            answer[right->x][right->y] = color; // 同步更新 answer
        } else { free(right); }

        free(cur); // 釋放走過的節點
    }

    return answer;
}
