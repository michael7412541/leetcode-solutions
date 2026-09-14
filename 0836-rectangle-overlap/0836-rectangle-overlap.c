bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
    bool answer = false;
    long long x_overlap = ((rec1[2] - rec2[0]) < 0) && ((rec1[0] - rec2[2]) > 0) || ((rec1[2] - rec2[0]) > 0) && ((rec1[0] - rec2[2]) < 0);
    long long y_overlap = ((rec1[3] - rec2[1]) < 0) && ((rec1[1] - rec2[3]) > 0) || ((rec1[3] - rec2[1]) > 0) && ((rec1[1] - rec2[3]) < 0) ;
    if(x_overlap  && y_overlap ) return true;
    else return false;
}