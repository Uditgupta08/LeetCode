class Solution {
public:
    bool check(vector<int>& nums) {
        bool flag = true;
        int n = nums.size();
        int maxi = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                if (flag) {
                    flag = false;
                    maxi = nums[i - 1]; 
                } else {
                    return false;
                }
            }
            if (nums[i] > maxi) {
                return false;
            }
        }
        if (!flag && nums[n - 1] > nums[0]) return false;
        return true;
    }
};