class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {{'I', 1},   {'V', 5},   {'X', 10},
                                      {'L', 50},  {'C', 100}, {'D', 500},
                                      {'M', 1000}};

        int n = s.length();
        int ans = m[s[0]];
        if (n == 1) {
            return ans;
        }
        for (int i = n - 1; i > 0; i--) {
            ans += m[s[i]];
            if (m[s[i]] > m[s[i - 1]]) {
                ans -= m[s[i - 1]];
                i--;
            }
        }
        if (m[s[0]] < m[s[1]]) {
            ans -= m[s[0]];
        }
        return ans;
    }
};