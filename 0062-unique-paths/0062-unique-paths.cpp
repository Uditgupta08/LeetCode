class Solution {
public:
    int tab(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        if (m == 1) {
            return a[n - 1];
        }
        for (int i = 2; i < m; i++) {
            vector<int> temp(n);
            temp[0] = 1;
            for (int j = 1; j < n; j++) {
                temp[j] = temp[j - 1] + a[j];
            }
            a = temp;
        }
        return a[n - 1];
    }
    int uniquePaths(int m, int n) { return tab(m, n); }
};