class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> deg(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                deg[it]++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for (auto it : adj[curr]) {
                deg[it]--;
                if (deg[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (ans.size() == n) {
            return true;
        }
        return false;
    }
};