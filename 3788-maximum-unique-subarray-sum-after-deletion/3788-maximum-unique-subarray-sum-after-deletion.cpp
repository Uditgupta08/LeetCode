class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> m;
        bool allNeg = true;
        int maxi = INT_MIN;
        for (auto it : nums) {
            if (it >= 0) {
                allNeg = false;
                m[it]++;
            }
            maxi = max(maxi, it);
        }
        if (m.size() == 0) {
            return maxi;
        }
        int ans = 0;
        for (auto it : m) {
            ans += it.first;
        }
        return ans;
    }
};