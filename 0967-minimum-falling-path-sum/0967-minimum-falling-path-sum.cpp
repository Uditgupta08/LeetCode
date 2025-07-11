class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> dp = a[0];
        for (int i = 1; i < n; i++) {
            vector<int> curr(n, 0);
            curr[0] = min(dp[0], dp[1]);
            curr[0] += a[i][0];
            for (int j = 1; j < n - 1; j++) {
                curr[j] = min(dp[j], min(dp[j - 1], dp[j + 1]));
                curr[j] += a[i][j];
            }
            curr[n - 1] = min(dp[n - 1], dp[n - 2]);
            curr[n - 1] += a[i][n - 1];
            dp = curr;
        }
        int ans = INT_MAX;
        for (auto it : dp) {
            ans = min(ans, it);
        }
        return ans;
    }
};