class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        for (auto it : a) {
            sum += it;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i : a) {
            for (int j = target; j >= i; j--) {
                dp[j] = dp[j] || dp[j - i];
            }
        }
        return dp[target];
    }
};