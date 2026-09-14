int largestOverlap(int** img1, int img1Size, int* img1ColSize, int** img2, int img2Size, int* img2ColSize) {
    int p1[900][2] = {0}, p2[900][2] = {0};
    int len1 = 0, len2 = 0;
    for(int i = 0; i < img1Size; i++){
        for(int j = 0; j <img1Size; j++){
            if(img1[i][j] == 1){
                p1[len1][0] = i;
                p1[len1++][1] = j;
            }
            if(img2[i][j] == 1){
                p2[len2][0] = i;
                p2[len2++][1] = j;
            }
        }
    }
    int count[65][65] = {0}, answer = 0;
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            int dc = p1[i][0] - p2[j][0] + img1Size - 1;
            int dr = p1[i][1] - p2[j][1] + img1Size - 1;
            count[dc][dr]++;
            if(count[dc][dr] > answer)
                answer = count[dc][dr];
        }
    }

    return answer;

}
