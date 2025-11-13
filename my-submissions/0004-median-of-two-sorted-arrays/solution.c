double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if(nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    
    int left = 0, right = nums1Size;
    int totalLeft = (nums1Size + nums2Size + 1)/2;
    
    while(left <= right){
        int i = (left + right)/2;
        int j = totalLeft - i;
        
        int nums1LMax = (i == 0) ? INT_MIN : nums1[i-1];
        int nums1RMin = (i == nums1Size) ? INT_MAX : nums1[i];
        int nums2LMax = (j == 0) ? INT_MIN : nums2[j-1];
        int nums2RMin = (j == nums2Size) ? INT_MAX : nums2[j];
        
        if(nums1LMax <= nums2RMin && nums2LMax <= nums1RMin) {
            if((nums1Size + nums2Size) % 2 == 1)
                return fmax(nums1LMax, nums2LMax);
            else
                return (fmax(nums1LMax, nums2LMax) + fmin(nums1RMin, nums2RMin))/2;
        }
        
        else if(nums1LMax > nums2RMin)
            right = i - 1;
        else
            left = i + 1;
        
        
        
    }
    return 0;
    
}
