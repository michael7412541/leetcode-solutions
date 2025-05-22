/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define BUCKETSIZE 1001

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if(nums1Size == 0 || nums1 == NULL || nums2 == NULL || nums2Size == 0)
        return NULL;
    int k = 0, i, hashtable[BUCKETSIZE], min_len = nums2Size;
    memset(hashtable, 0, sizeof(hashtable));
    if(nums1Size < nums2Size)
        min_len = nums1Size;
    int* answer = (int*)malloc(sizeof(int)*min_len);
    for(i = 0; i < nums1Size; i++) {
        if(hashtable[nums1[i]] == 0)
            hashtable[nums1[i]]++;
    }
    for(i = 0; i < nums2Size; i++) {
        if(hashtable[nums2[i]] != 0) {
            hashtable[nums2[i]] = 0;
            answer[k] = nums2[i];
            k++;
        }
    }
    *returnSize = k;
    return answer;
}
