double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size = nums1Size + nums2Size, flag = size / 2;
    int point1 = 0, point2 = 0, nums[ flag+1 ], index = 0;
    while (index <= flag) {
        int temp1 = 1e6, temp2 = 1e6;
        if (point1 < nums1Size) temp1 = nums1[ point1 ];
        if (point2 < nums2Size) temp2 = nums2[ point2 ];
        if (temp1 > temp2) point2++;
        else               point1++;
        nums[ index++ ] = temp1 > temp2 ? temp2 : temp1;
    }
    if (!(size % 2))
        return ((double)(nums[flag] + nums[flag-1])) / 2;
    return nums[flag];
}