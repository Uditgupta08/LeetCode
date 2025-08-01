class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> curr(m + 1, 0), prev(m + 1, 0);
        for (int i = 0; i <= m; i++) {
            prev[i] = i;
        }
        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = min(prev[j - 1], min(prev[j], curr[j - 1])) + 1;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};