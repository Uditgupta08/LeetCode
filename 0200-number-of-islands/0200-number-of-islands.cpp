class Solution {
public:
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, 1, -1, 0};
    // void dfs(int x, int y, vector<vector<char>> grid,
    //          vector<vector<int>>& vis) {
    //     vis[x][y] = 1;
    //     for (int i = 0; i < 4; i++) {
    //         int newx = x + dx[i];
    //         int newy = y + dy[i];
    //         if (newx >= 0 && newy >= 0 && newx < grid.size() &&
    //             newy < grid[0].size() && grid[newx][newy] == '1' &&
    //             !vis[newx][newy]) {
    //             dfs(newx, newy, grid, vis);
    //         }
    //     }
    // }
    void bfs(int x, int y, vector<vector<char>> &grid,
             vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = 1;
        while (!q.empty()) {
            int currx = q.front().first;
            int curry = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newx = currx + dx[i];
                int newy = curry + dy[i];
                if (newx >= 0 && newy >= 0 && newx < grid.size() &&
                    newy < grid[0].size() && grid[newx][newy] == '1' &&
                    !vis[newx][newy]) {
                    q.push({newx, newy});
                    vis[newx][newy] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};