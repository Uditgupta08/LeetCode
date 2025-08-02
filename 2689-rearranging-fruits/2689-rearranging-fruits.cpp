class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        unordered_map<int, int> m;
        vector<int> b1;
        vector<int> b2;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            m[basket1[i]]++;
            m[basket2[i]]--;
            mini = min({mini, basket1[i], basket2[i]});
        }
        for (auto it : m) {
            if (it.second % 2 != 0) {
                return -1;
            }
            int times = abs(it.second) / 2;
            if (it.second > 0) {
                while (times--) {
                    b1.push_back(it.first);
                }
            } else {
                while (times--) {
                    b2.push_back(it.first);
                }
            }
        }
        sort(begin(b1), end(b1));
        sort(b2.rbegin(), b2.rend());
        long long ans = 0;
        for (int i = 0; i < b1.size(); i++) {
            int x = b1[i], y = b2[i];
            ans += min(min(x, y), 2 * mini);
        }
        return ans;
    }
};