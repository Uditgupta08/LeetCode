class Solution {
public:
    bool isPalindrome(string s, int l, int r) {
        while (l <= r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    void solve(string s, int ind, vector<string>& par,
               vector<vector<string>>& ans) {
        if (ind == s.length()) {
            ans.push_back(par);
            return;
        }
        for (int i = ind;i < s.length(); i++) {
            if (isPalindrome(s, ind, i)) {
                par.push_back(s.substr(ind, i - ind + 1));
                solve(s, i+1, par, ans);
                par.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> par;
        solve(s,0,par,ans);
        return ans;
    }
};