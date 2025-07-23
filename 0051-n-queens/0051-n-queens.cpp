class Solution {
public:
    bool isSafe(int x, int y, int n, vector<string> curr) {
        int tempx = x;
        int tempy = y;
        while (tempx >= 0 && tempy >= 0) {
            if (curr[tempx][tempy] == 'Q') {
                return false;
            }
            tempx--;
            tempy--;
        }
        tempx = x;
        tempy = y;
        while (tempy >= 0) {
            if (curr[tempx][tempy] == 'Q') {
                return false;
            }
            tempy--;
        }
        tempy = y;
        while (tempx < n && tempy >= 0) {
            if (curr[tempx][tempy] == 'Q') {
                return false;
            }
            tempy--;
            tempx++;
        }
        return true;
    }
    void solve(int n, int col, vector<string>& curr,
               vector<vector<string>>& ans) {
        if (col == n) {
            ans.push_back(curr);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, n, curr)) {
                curr[row][col] = 'Q';
                solve(n, col + 1, curr, ans);
                curr[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr(n);
        vector<vector<string>> ans;
        string s = string(n, '.');
        for (int i = 0; i < n; i++) {
            curr[i] = s;
        }
        solve(n, 0, curr, ans);
        return ans;
    }
};