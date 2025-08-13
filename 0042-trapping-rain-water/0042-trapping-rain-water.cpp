class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int l = 0;
        int r = n - 1;
        int lmax = 0;
        int rmax = 0;
        int ans = 0;
        while (l < r) {
            if (a[l] < a[r]) {
                lmax = max(lmax, a[l]);
                ans += lmax - a[l];
                l++;
            } else {
                rmax = max(rmax, a[r]);
                ans += rmax - a[r];
                r--;
            }
        }
        return ans;
    }
};