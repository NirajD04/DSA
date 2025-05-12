class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        // Min-heap: (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> result(n + 1, INT_MAX);

        result[k] = 0; // k here is source;
        pq.push({0, k});

        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto& v : adj[node]) {
                int adjnode = v.first;
                int wt = v.second;

                if (dist + wt < result[adjnode]) {
                    result[adjnode] = dist + wt;
                    pq.push({dist + wt, adjnode});
                }
            }
        }
        int maxdelay=0;
        for(int i=1; i<=n; i++){
            if(result[i]==INT_MAX) return -1;
            if(result[i] > maxdelay){
                maxdelay=result[i];
            }
        }
        return maxdelay;
    }
};