class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        int maxi = 0;
        for (auto it : events) {
            maxi = max(maxi, it[1]);
        }
        int curr = 1;
        int i = 0;
        while (curr <= maxi) {
            while (i < n && events[i][0] == curr) {
                pq.push(events[i++][1]);
            }
            while (!pq.empty() && pq.top() < curr) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
            curr++;
        }
        return ans;
    }
};
