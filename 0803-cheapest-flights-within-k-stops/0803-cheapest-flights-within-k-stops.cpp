class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        // vector<vector<pair<int, int>>> adj(n);
        // for (auto it : flights) {
        //     adj[it[0]].push_back({it[1], it[2]});
        // }
        // priority_queue<pair<int, pair<int, int>>,
        //                vector<pair<int, pair<int, int>>>,
        //                greater<pair<int, pair<int, int>>>>
        //     q;
        //  q.push({0, {src, 0}});
        // vector<int> minStops(n, INT_MAX);
        // while (!q.empty()) {
        //     auto it = q.top(); q.pop();
        //     int cost = it.first;
        //     int curr = it.second.first;
        //     int stops = it.second.second;
        //     if (curr == dst) return cost;
        //     if (stops > k || stops > minStops[curr]) continue;
        //     minStops[curr] = stops;
        //     for (auto& [nextNode, price] : adj[curr]) {
        //         q.push({cost + price, {nextNode, stops + 1}});
        //     }
        // }
        // return -1;

        vector<vector<pair<int, int>>> adjL(n);
        for (auto it : flights) {
            adjL[it[0]].push_back({it[1], it[2]});
        }

        // THIS MAKES A MIN-HEAP
        priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;

        vector<int> minStops(n, INT_MAX);
        pq.push({0, {src, 0}});
        while(!pq.empty()){
            int cost = pq.top().first;
            int curr = pq.top().second.first;
            int currk = pq.top().second.second;
            if (curr == dst) return cost;
            pq.pop();
            if(currk > k || currk > minStops[curr]){
                continue;
            }
            minStops[curr] = currk;
            for(auto it : adjL[curr]){
                pq.push({cost+it.second,{it.first,currk+1}});
            }
        }
        return -1;
    }
};