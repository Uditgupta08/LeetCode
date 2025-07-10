class Solution {
public:
    int solve(vector<int> a, int l, int r) {
        int prev2 = 0;
        int prev1 = a[l];
        for (int i = l + 1; i < r; i++) {
            int curr = max(a[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& a) {
        if (a.size() == 1) {
            return a[0];
        }
        return max(solve(a, 0, a.size() - 1), solve(a, 1, a.size()));
    }
};