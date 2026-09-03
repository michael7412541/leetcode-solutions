


bool uniformArray(int* nums1, int nums1Size) {
    bool odd = true, even = true;
    int min = INT_MAX;
    for(int i = 0; i < nums1Size; i++){
        if(nums1[i] % 2 != 0)
            even = false;
        if(nums1[i] < min)
            min = nums1[i];
    } 
    if(min % 2 == 0)
        odd = false;
    return even || odd;
}
