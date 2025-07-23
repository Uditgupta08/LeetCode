class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> st;
        unordered_map<int, int> nextGreater;
        vector<int> res;
        for (int i = n2 - 1; i >= 0; i--) {
            while (!st.empty() && nums2[i] > st.top()) {
                st.pop();
            }
            if (st.empty()) {
                nextGreater[nums2[i]] = -1;
            } else {
                nextGreater[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for (int it : nums1) {
            res.push_back(nextGreater[it]);
        }
        return res;
    }
};