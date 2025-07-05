class DisjointSet {
    vector<int> rank, parent, size;

public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> m;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string curr = accounts[i][j];
                if (m.find(curr) == m.end()) {
                    m[curr] = i;
                } else {
                    ds.unionBySize(i, m[curr]);
                }
            }
        }
        vector<vector<string>> ans(n);
        for (auto it : m) {
            string curr = it.first;
            int node = ds.findUPar(it.second);
            ans[node].push_back(curr);
        }
        vector<vector<string>> res;
        for (int i = 0; i < n; i++) {
            if (ans[i].size() == 0) {
                continue;
            }
            sort(ans[i].begin(), ans[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : ans[i]) {
                temp.push_back(it);
            }
            res.push_back(temp);
        }
        return res;
    }
};