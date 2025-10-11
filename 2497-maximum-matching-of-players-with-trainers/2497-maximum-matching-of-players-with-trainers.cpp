class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = g.size() - 1;
        int si = s.size() - 1;
        int ans = 0;
        while (gi >= 0 && si >= 0) {
            if (g[gi] > s[si]) {
                gi--;
            } else if (g[gi] <= s[si]) {
                si--;
                gi--;
                ans++;
            }
        }
        return ans;
    }
};