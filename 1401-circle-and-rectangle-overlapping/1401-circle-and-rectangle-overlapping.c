bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    /*int CL_x = xCenter - radius, CR_x = xCenter + radius;
    int CL_y = yCenter - radius, CR_y = yCenter + radius;
    bool overlap_x = true, overlap_y = true;
    if(x1 > CL_x && x1 > CR_x) overlap_x = false;
    if(x2 < CL_x && x2 < CR_x) overlap_x = false;
    if(y1 > CL_y && y1 > CR_y) overlap_y = false;

    if(y2 < CL_y && y2 < CR_y) overlap_y = false;
    return overlap_x & overlap_y;*/

    int x = x2, y = y2, distance;
    if(x1 <= xCenter && xCenter <= x2) x = xCenter;
    if(xCenter <= x1) x = x1;

    if(y1 <= yCenter && yCenter <= y2) y = yCenter;
    if(yCenter <= y1) y = y1;

    distance = pow((x - xCenter),2) + pow((y - yCenter),2);
    return distance <= radius*radius; 
}