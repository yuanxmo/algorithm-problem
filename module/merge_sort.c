int *tempNums; // 定义的临时数组

void merge_sort(int *nums, int l, int r) {
    if (l >= r)
        return;
    int mid = l + r >> 1;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid+1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (nums[i] < nums[j])
            tempNums[ k++ ] = nums[ i++ ];
        else
            tempNums[ k++ ] = nums[ j++ ];
    }
    while (i <= mid)
        tempNums[ k++ ] = nums[ i++ ];
    while (j <= r)
        tempNums[ k++ ] = nums[ j++ ];
    for (i = l, j = 0; i <= r; i++, j++)
        nums[i] = tempNums[j];
}