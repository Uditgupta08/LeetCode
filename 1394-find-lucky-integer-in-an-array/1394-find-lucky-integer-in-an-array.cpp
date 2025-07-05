class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> m;
        for (auto it : arr) {
            m[it]++;
        }
        int ans = -1;
        for (auto it : m) {
            if (it.first == it.second) {
                ans = max(ans, it.first);
            }
        }
        return ans;
    }
};