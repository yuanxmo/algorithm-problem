void quick_sort(int *nums, int l, int r) {
    if (l >= r)
        return;
    int i = l - 1, j = r + 1, x = nums[l + r >> 1];
    while (i < j) {
        do
            i++;
        while (nums[i] < x);
        do
            j--;
        while (nums[j] > x);
        if (i < j) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
    quick_sort(nums, l, j), quick_sort(nums, j + 1, r);
}