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

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int copy[ numsSize ];
    for (int i = 0; i < numsSize; i++)
        copy[i] = nums[i];
    quick_sort(copy, 0, numsSize - 1);
    int l = 0, r = numsSize - 1;
    while (l < r) {
        int temp = copy[l] + copy[r] - target;
        if (temp == 0)  break;
        else if (temp > 0) r --;
        else if (temp < 0) l ++;
    }
    l = copy[l]; r = copy[r];
    int i,j;
    for (i = 0; i < numsSize - 1; i++)
        if (nums[i] == l) break;
    for (j = numsSize - 1; j >= 0; j--)
        if (nums[j] == r) break;
    int *ans = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    ans[0] = i; ans[1] = j;
    return ans;
}