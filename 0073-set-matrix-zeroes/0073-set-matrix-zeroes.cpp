class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        bool r = false;
        bool c = false;
        int n = a.size();
        int m = a[0].size();

        for (int i = 0; i < m; i++) {
            if (a[0][i] == 0) {
                r = true;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i][0] == 0) {
                c = true;
                break;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (a[i][j] == 0) {
                    a[i][0] = 0;
                    a[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (a[i][0] == 0) {
                for (int j = 1; j < m; j++) {
                    a[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            if (a[0][i] == 0) {
                for (int j = 1; j < n; j++) {
                    a[j][i] = 0;
                }
            }
        }
        if (r) {
            for (int i = 0; i < m; i++) {
                a[0][i] = 0;
            }
        }
        if (c) {
            for (int i = 0; i < n; i++) {
                a[i][0] = 0;
            }
        }
    }
};