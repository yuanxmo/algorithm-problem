char* longestPalindrome(char* s) {
    int size = strlen(s);
    if (size < 2) return s;
    int max = 1, begin = 0;
    int dp[ size ][ size ];
    for (int i = 0; i < size; i++) dp[i][i] = 1;
    for (int len = 2; len <= size; len++) {
        for (int i = 0; i < size; i++) {
            int j = len + i - 1;
            if (j >= size)  break;
            if (s[i] != s[j])
                dp[i][j] = 0;
            else {
                if (j - i < 3) dp[i][j] = 1;
                else           dp[i][j] = dp[ i + 1 ][ j - 1 ];
            }
            if (dp[i][j] && j - i + 1 > max) {
                max = j - i + 1;
                begin = i;
            }
        }
    }
    // 构造结果
    char *ans = (char*)malloc(max + 1);
    for (int i = 0; i < max; i++)
        ans[i] = s[ begin + i ];
    ans[max] = '\0';
    return ans;
}