class Solution {
public:
    int maxProfit(vector<int>& a) {
        int mini = a[0];
        int ans = 0;
        for (int i = 1; i < a.size(); i++) {
            mini = min(mini, a[i]);
            ans = max(ans, a[i] - mini);
        }
        return ans;
    }
};