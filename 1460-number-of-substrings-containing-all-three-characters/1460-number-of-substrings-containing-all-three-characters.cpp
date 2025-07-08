class Solution {
public:
    int numberOfSubstrings(string s) {
        int r = 0;
        int l = 0;
        int ans = 0;
        int n = s.length();
        unordered_map<char, int> m;
        while (r < n) {
            m[s[r]]++;
            while (m.size() == 3) {
                ans += n - r;
                m[s[l]]--;
                if (m[s[l]] == 0) {
                    m.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};