class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        int prev2 = 0;
        int prev1 = a[0];
        for (int i = 1; i < n; i++) {
            int curr = max(a[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};