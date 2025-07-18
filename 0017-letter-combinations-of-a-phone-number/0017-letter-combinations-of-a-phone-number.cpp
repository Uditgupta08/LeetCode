class Solution {
public:
    void solve(int curr, string s, string& temp, unordered_map<char, string>& m,
               vector<string>& ans) {
        if (curr >= s.length()) {
            ans.push_back(temp);
            return;
        }

        char ch = s[curr];
        string str = m[ch];
        for (int i = 0; i < str.length(); i++) {
            temp.push_back(str[i]);
            solve(curr + 1, s, temp, m, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        vector<string> ans;
        string temp = "";
        solve(0, digits, temp, m, ans);
        return ans;
    }
};
