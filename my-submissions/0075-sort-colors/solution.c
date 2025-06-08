int compare_ints(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
void sortColors(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare_ints);
}
