class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int curr = st.top();
                st.pop();
                int prev = -1;
                if (!st.empty()) {
                    prev = st.top();
                }
                ans = max(ans, heights[curr] * (i - prev - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            int nse = heights.size();
            int prev = -1;
            if (!st.empty()) {
                prev = st.top();
            }
            ans = max(ans, heights[curr] * (nse - prev - 1));
        }
        return ans;
    }
};