class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> ans;
        if (a.empty() || a[0].empty()) return ans;
        int n = a.size();
        int m = a[0].size();
        int t = 0, b = n - 1;
        int l = 0, r = m - 1;
        while (t <= b && l <= r) {
            for (int j = l; j <= r; ++j)
                ans.push_back(a[t][j]);
            t++;
            for (int i = t; i <= b; ++i)
                ans.push_back(a[i][r]);
            r--;
            if (t <= b) {
                for (int j = r; j >= l; --j)
                    ans.push_back(a[b][j]);
                b--;
            }
            if (l <= r) {
                for (int i = b; i >= t; --i)
                    ans.push_back(a[i][l]);
                l++;
            }
        }
        return ans;
    }
};