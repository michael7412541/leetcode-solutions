/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


void dfsfill(int **image, int x, int y, int original, int color, int m, int n) {
    if(x < 0 || x >= m || y < 0 || y >= n)
        return;
    if(image[x][y] != original)
        return;
    if(image[x][y] == original) {
        image[x][y] = color;
        dfsfill(image, x+1, y, original, color, m, n);
        dfsfill(image, x-1, y, original, color, m, n);
        dfsfill(image, x, y-1, original, color, m, n);
        dfsfill(image, x, y+1, original, color, m, n);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    
    
    int i = 0;
    //int **answer = (int**)malloc(imageSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));//***
    *returnSize = imageSize;
    for(i = 0; i < imageSize; i++) {
        //answer[i] = (int*)calloc(imageColSize[i], sizeof(int));
        (*returnColumnSizes)[i] = imageColSize[i];
        //returnColumnSizes[i] = imageColSize[i];
    }
    if(image[sr][sc] == color) 
        return image;
    int original = image[sr][sc];
    dfsfill(image, sr, sc, original, color, imageSize, imageColSize[0]);
    
    return image;
    
}
