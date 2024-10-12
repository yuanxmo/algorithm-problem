int lengthOfLongestSubstring(char* s) {
    int hash[ 256 ] = {0};
    int size = strlen(s);
    int r = -1, ans = 0;
    for (int l = 0; l < size; l++) {
        if (l) {
            hash[ s[l-1] ] = 0;
        }
        while (r + 1 < size && !hash[ s[ r + 1 ] ]) {
            hash[ s[ r + 1 ] ] = 1;
            r ++;
        }
        ans = ans > r - l + 1 ? ans : r - l + 1;
    }
    return ans;
}