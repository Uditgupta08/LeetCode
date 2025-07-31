class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc,
                                  int color) {
        int n = img.size();
        int m = img[0].size();
        int ini = img[sr][sc];
        if (ini == color) return img;
        img[sr][sc] = color;
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    img[nrow][ncol] == ini) {
                    q.push({nrow, ncol});
                    img[nrow][ncol] = color;
                }
            }
        }
        return img;
    }
};