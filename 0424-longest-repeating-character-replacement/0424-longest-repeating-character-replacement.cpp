class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int tempMax = 0;
        unordered_map<char, int> m(26);
        while (r < s.length()) {
            m[s[r]]++;
            tempMax = max(tempMax, m[s[r]]);
            if ((r - l + 1) - tempMax > k) {
                m[s[l]]--;
                l++;
            }
            if ((r - l + 1) - tempMax <= k) {
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
};