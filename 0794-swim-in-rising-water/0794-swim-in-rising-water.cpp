class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<>> pq;
        dis[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};
        while (!pq.empty()) {
            auto [t, pos] = pq.top(); pq.pop();
            int r = pos.first, c = pos.second;
            if (r == n - 1 && c == n - 1) return t;
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
                    int newTime = max(t, grid[nr][nc]);
                    if (newTime < dis[nr][nc]) {
                        dis[nr][nc] = newTime;
                        pq.push({newTime, {nr, nc}});
                    }
                }
            }
        }
        return -1; 
    }
};