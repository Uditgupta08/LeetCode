class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<int> rprev(m);
        rprev[0] = a[0][0];
        for (int i = 1; i < m; i++) {
            rprev[i] = rprev[i - 1] + a[0][i];
        }
        for (int i = 1; i < n; i++) {
            rprev[0] += a[i][0];
            for (int j = 1; j < m; j++) {
                rprev[j] = min(rprev[j - 1], rprev[j]);
                rprev[j] += a[i][j];
            }
        }
        return rprev[m - 1];
    }
};