class Solution {
public:
    void twoSum(vector<int>& nums, int target, int curr,
                vector<vector<int>>& ans) {
        int l = curr + 1;
        int r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else if (nums[l] + nums[r] < target) {
                l++;
            } else {
                ans.push_back({nums[curr], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) {
                    l++;
                }
                while (l < r && nums[r] == nums[r - 1]) {
                    r--;
                }
                l++;
                r--;
            }
        }
        return;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            twoSum(nums, -nums[i], i, ans);
        }
        return ans;
    }
};
