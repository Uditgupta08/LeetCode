class Solution {
public:
    bool dfs(string& s, vector<string>& wordDict, int ind, vector<int>& dp) {
        if (ind == s.size())
            return true;
        if (dp[ind] != -1)
            return dp[ind];
        for (int i = 0, n = wordDict.size(); i < n; ++i) {
            int len = wordDict[i].size();
            if (ind + len <= s.size() &&
                s.compare(ind, len, wordDict[i]) == 0) {
                if (dfs(s, wordDict, ind + len, dp))
                    return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                int len = wordDict[j].size();
                string word = wordDict[j];
                if (len <= i && s.substr(i - len, len) == word && dp[i - len]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};