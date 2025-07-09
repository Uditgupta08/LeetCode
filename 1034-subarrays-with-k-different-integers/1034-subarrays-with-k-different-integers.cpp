class Solution {
public:
    int helper(vector<int> nums, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        if (k < 0) {
            return 0;
        }
        unordered_map<int, int> m;
        while (r < nums.size()) {
            m[nums[r]]++;
            while(m.size() > k) {
                m[nums[l]]--;
                if (m[nums[l]] == 0) {
                    m.erase(nums[l]);
                }
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};