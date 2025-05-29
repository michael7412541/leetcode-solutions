/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if(nums1 == NULL || nums1Size == 0 || nums2 == NULL || nums2Size == 0)
        return NULL;
    
    int *hashmap = (int*)malloc(1001 * sizeof(int));
    int *answer = (int*)malloc(nums1Size * sizeof(int));
    memset(hashmap, 0, 1001*sizeof(int));
    int i = 0, count = 0;
    for(i = 0; i < nums1Size; i++)
    {
        hashmap[nums1[i]] ++;
    }
    for(i = 0; i < nums2Size; i++)
    {
        if(hashmap[nums2[i]] > 0)
        {
            answer[count] = nums2[i];
            hashmap[nums2[i]]--;
            count++;    
        }
    }
    *returnSize = count;
    return answer;
}

//時間複雜度為O(m+n)
//answer的淺在記憶體浪費，最好是用min(nums1Size, nums2Size)
//malloc可以改用calloc 會將初始射程0 
// int *hashmap = (int*)calloc(1001, sizeof(int));

