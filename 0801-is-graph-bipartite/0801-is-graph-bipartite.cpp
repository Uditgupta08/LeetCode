class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                q.push({i, 1});
                while (!q.empty()) {
                    int currNode = q.front().first;
                    int currColor = q.front().second;
                    q.pop();
                    for (int j = 0; j < graph[currNode].size(); j++) {
                        int curr = graph[currNode][j];
                        if (!vis[curr]) {
                            q.push({curr, 3 - currColor});
                            vis[curr] = 3 - currColor;
                        } else if (vis[curr] != 3 - currColor) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};