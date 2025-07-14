class Solution {
public:
    int ways(vector<int> a, int t) {
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= t; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= a[i - 1]) {
                    dp[i][j] += dp[i - 1][j - a[i - 1]];
                }
            }
        }
        return dp[n][t];
    }
    int findTargetSumWays(vector<int>& a, int t) {
        int total = 0;
        for (auto it : a) {
            total += it;
        }
        if (total - abs(t) < 0 || (total - t) % 2) {
            return 0;
        }
        return ways(a, (total - t) / 2);
    }
};