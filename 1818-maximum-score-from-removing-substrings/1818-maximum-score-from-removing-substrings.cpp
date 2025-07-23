class Solution {
public:
    int solve(string& s, int x, string curr) {
        int ans = 0;
        int i = 0;
        int n = s.size();
        while (i < n - 1) {
            if (s[i] == curr[0] && s[i + 1] == curr[1]) {
                n -= 2;
                ans += x;
                s.erase(i, 2);
                if (i > 0)
                    i--;
            } else {
                i++;
            }
        }
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        string sa = "ab";
        string sb = "ba";
        if (y > x) {
            swap(x, y);
            swap(sa, sb);
        }
        return solve(s, x, sa) + solve(s, y, sb);
    }
};