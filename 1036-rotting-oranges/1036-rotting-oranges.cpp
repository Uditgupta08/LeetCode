class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //{{coordinate of orange},currTime}
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m));

        // Rotten Oranges Initially
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
            }
        }

        int time = 0;
        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, -1, 0, 1};
        // {top, left, bottom, right}
        while (!q.empty()) {
            // POP THE FRONT OF QUEUE AND CHECK ITS NEIGHBOURS
            int currRow = q.front().first.first;
            int currCol = q.front().first.second;
            int currTime = q.front().second;
            q.pop();
            time = max(currTime, time);
            for (int i = 0; i < 4; i++) {
                int nRow = currRow + row[i];
                int nCol = currCol + col[i];
                if (nRow < n && nRow >= 0 && nCol < m && nCol >= 0 &&
                    vis[nRow][nCol] != 2 && grid[nRow][nCol] == 1) {
                    q.push({{nRow, nCol}, currTime + 1});
                    vis[nRow][nCol] = 2;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1;
                }
            }
        }
        return time;
    }
};