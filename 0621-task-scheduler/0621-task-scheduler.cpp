class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) {
            return tasks.size();
        }
        unordered_map<char, int> m;
        for (char ch : tasks) {
            m[ch]++;
        }
        priority_queue<int> pq;
        for (auto it : m) {
            pq.push(it.second);
        }
        int ans = 0;
        while (!pq.empty()) {
            int req = n + 1;
            vector<int> temp;
            while (req > 0 && !pq.empty()) {
                int curr = pq.top();
                pq.pop();
                curr--;
                ans++;
                req--;
                if (curr > 0) {
                    temp.push_back(curr);
                }
            }
            for (int it : temp) {
                pq.push(it);
            }
            if (!pq.empty()) {
                ans += req;
            }
        }
        return ans;
    }
};