class Solution {
public:
    int helper(vector<int> nums, int k) {
        if (k < 0) {
            return 0;
        }
        int l = 0;
        int r = 0;
        int ans = 0;
        int odd = 0;
        while (r < nums.size()) {
            if (nums[r] % 2 == 1) {
                odd++;
            }
            while (odd > k) {
                if (nums[l] % 2 == 1) {
                    odd--;
                }
                l++;
            }
            ans = ans + (r - l + 1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};