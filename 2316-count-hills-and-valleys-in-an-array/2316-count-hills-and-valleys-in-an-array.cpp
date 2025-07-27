class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                temp.push_back(nums[i]);
            }
        }
        int ans = 0;
        for (int curr = 1; curr < temp.size() - 1; curr++) {
            if ((temp[curr] > temp[curr - 1] && temp[curr] > temp[curr + 1]) ||
                (temp[curr] < temp[curr - 1] && temp[curr] < temp[curr + 1])) {
                ans++;
            }
        }
        return ans;
    }
};