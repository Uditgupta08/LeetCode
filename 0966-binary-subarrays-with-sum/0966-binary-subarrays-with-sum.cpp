class Solution {
public:
    int helper(vector<int> nums, int goal) {
        if (goal < 0) {
            return 0;
        }
        int l = 0;
        int r = 0;
        int ans = 0;
        int sum = 0;
        while (r < nums.size()) {
            sum += nums[r];
            while (sum > goal) {
                sum = sum - nums[l];
                l = l + 1;
            }
            ans = ans + (r - l + 1);
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
    }
};