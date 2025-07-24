class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            // if front is less than start of currect window then pop
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // if curr ele > ele at back of dq then that ele(in dq) will not be used in next windows
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // just push curr ele(we may use it in next window)
            dq.push_back(i);

            // just tell the answer for each subarray after kth index
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};