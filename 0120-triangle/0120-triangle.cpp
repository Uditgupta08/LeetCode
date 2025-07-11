class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> dp(n);
        dp[0] = a[0][0];
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + a[i][i];
            for (int j = i - 1; j > 0; j--) {
                dp[j] = min(dp[j - 1], dp[j]) + a[i][j];
            }
            dp[0] = dp[0] + a[i][0];
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};
