class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int r = 0;
        int n = fruits.size();
        int ans = INT_MIN;
        unordered_map<int, int> m;
        while (r < n) {
            m[fruits[r]]++;
            while (m.size() > 2) {
                m[fruits[l]]--;
                if (m[fruits[l]] == 0) {
                    m.erase(fruits[l]);
                }
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};