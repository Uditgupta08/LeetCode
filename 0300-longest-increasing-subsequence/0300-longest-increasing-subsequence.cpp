class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int curr = 1; curr < n; curr++) {
            for (int prev = 0; prev < curr; prev++) {
                if (a[curr] > a[prev]) {
                    dp[curr] = max(dp[curr], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[curr]);
        }
        return maxi;
    }
};