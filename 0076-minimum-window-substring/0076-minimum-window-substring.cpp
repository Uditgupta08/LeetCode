class Solution {
public:
    string minWindow(string s, string t) {
        int ans = INT_MAX;
        unordered_map<char, int> m;
        int l = 0;
        int r = 0;
        int count = 0;
        int start = -1;
        int n = s.size();
        for (auto it : t) {
            m[it]++;
        }
        while (r < n) {
            if (m[s[r]] > 0) {
                count++;
            }
            m[s[r]]--;
            while (count == t.size()) {
                if (ans > (r - l + 1)) {
                    ans = r - l + 1;
                    start = l;
                }
                m[s[l]]++;
                if (m[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }
        if (start == -1) {
            return "";
        }
        string res = s.substr(start, ans);
        return res;
    }
};