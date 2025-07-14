class Solution {
public:
    int coinChange(vector<int>& a, int amount) {
        vector<long long> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++) {
            for (auto it : a) {
                if (i - it >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - it]);
                }
            }
        }
        if (dp[amount] != INT_MAX) {
            return dp[amount];
        }
        return -1;
    }
};