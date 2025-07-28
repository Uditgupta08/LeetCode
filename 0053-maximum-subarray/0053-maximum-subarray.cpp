class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for (int n : nums) {
            if (sum < 0) {
                ans = max(ans,sum);
                sum = 0;
            }
            sum += n;
            ans = max(ans, sum);
        }
        return ans;
    }
};