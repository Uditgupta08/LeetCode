class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n);
        dp[0] = a[0];
        for (int i = 1; i < n; i++) {
            int notTake = dp[i - 1];
            int take = a[i];
            if (i > 1) {
                take += dp[i - 2];
            }
            dp[i] = max(take, notTake);
        }
        return dp[n - 1];
    }
};