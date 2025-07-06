class DisjointSet {
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv)
            return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    continue;
                }
                vector<int> dr = {-1, 0, 1, 0};
                vector<int> dc = {0, 1, 0, -1};
                for (int i = 0; i < 4; i++) {
                    int newr = r + dr[i];
                    int newc = c + dc[i];
                    if (newr < n && newr >= 0 && newc < n && newc >= 0 &&
                        grid[newr][newc] == 1) {
                        int node = r * n + c;
                        int adj = newr * n + newc;
                        ds.unionBySize(node, adj);
                    }
                }
            }
        }
        int ans = 0;
        bool hasZero = false;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    hasZero = true;
                    vector<int> dr = {-1, 0, 1, 0};
                    vector<int> dc = {0, 1, 0, -1};
                    set<int> components;
                    for (int i = 0; i < 4; i++) {
                        int newr = r + dr[i];
                        int newc = c + dc[i];
                        if (newr < n && newr >= 0 && newc < n && newc >= 0) {
                            if (grid[newr][newc] == 1) {
                                components.insert(ds.findUPar(newr * n + newc));
                            }
                        }
                    }
                    int tot = 0;
                    for (auto it : components) {
                        tot += ds.size[it];
                    }
                    ans = max(ans, tot + 1);
                }
            }
        }
        if (!hasZero) {
            for (int i = 0; i < n * n; i++) {
                if (ds.findUPar(i) == i)
                    ans = max(ans, ds.size[i]);
            }
        }
        return ans;
    }
};