class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> m;
        for (auto it : s) {
            m[it]++;
        }
        for (auto it : m) {
            pq.push({it.second, it.first});
        }
        string ans = "";
        while (!pq.empty()) {
            int count = pq.top().first;
            char curr = pq.top().second;
            ans += string(count, curr);
            pq.pop();
        }
        return ans;
    }
};