class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> curr(m + 1, 0), prev(m + 1, 0);
        for (int t1 = 1; t1 <= n; t1++) {
            for (int t2 = 1; t2 <= m; t2++) {
                if (text1[t1 - 1] != text2[t2 - 1]) {
                    curr[t2] = max(curr[t2 - 1], prev[t2]);
                } else {
                    curr[t2] = prev[t2 - 1] + 1;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};