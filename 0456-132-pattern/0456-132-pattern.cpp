class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int k = INT_MIN;
        int n = nums.size();
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < k) {
                return true;
            }
            while (!st.empty() && st.top() < nums[i]) {
                k = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};