class Solution {
public:
    int ways(vector<int> a, int t) {
        int n = a.size();
        // dp[i][j]
        // i -> curr ele, j -> sum
        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
        // only 1 way to get sum = 0 using 0 elements
        dp[0][0] = 1;

        // you cant make upto target without taking atleast 1 ele
        for(int i = 1; i < t; i++){
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= t; j++) {
                // notTake case
                dp[i][j] = dp[i - 1][j];
                // take case
                if (j >= a[i - 1]) {
                    dp[i][j] += dp[i - 1][j - a[i - 1]];
                }
            }
        }
        return dp[n][t];
    }
    // HERE 't' is difference between both subsets
    int findTargetSumWays(vector<int>& a, int t) {
        int total = 0;
        for (auto it : a) {
            total += it;
        }
        // sum cant be smaller than difference
        // if (total + t) is odd then we cant divide into 2 subsets
        if (total - abs(t) < 0 || (total + t) % 2) {
            return 0;
        }
        return ways(a, (total + t) / 2);
    }
};