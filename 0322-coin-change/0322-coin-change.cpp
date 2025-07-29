class Solution {
public:
    int coinChange(vector<int>& a, int amount) {
        vector<long long> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int currCoin = 1; currCoin <= amount; currCoin++) {
            for (auto currAmount : a) {
                if (currCoin - currAmount >= 0) {
                    dp[currCoin] =
                        min(dp[currCoin], 1 + dp[currCoin - currAmount]);
                }
            }
        }
        if (dp[amount] != INT_MAX) {
            return dp[amount];
        }
        return -1;
    }
};