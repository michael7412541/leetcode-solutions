int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int pt1 = 0, pt2 = 0;
    while(pt1 < nums1Size&& pt2 < nums2Size){
        if(nums1[pt1] == nums2[pt2])
            return nums1[pt1];
        else if(nums1[pt1] > nums2[pt2])
            pt2++;
        else
            pt1++;
    }
    return -1;
}
