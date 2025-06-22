class Solution {
public:
    bool dfs(int u, int v, unordered_map<int, vector<int>>& adj,
             vector<bool>& visited) {

        visited[u] = true;

        if (u == v) {   // ngbr  ke through  u-> ngbr->  v  i.e u== v connected
            return true;
        }

        for (auto ngbr : adj[u]) {
            if (visited[ngbr])
                continue;
            if (dfs(ngbr, v, adj, visited)) {
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> adj;
        

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            vector<bool> visited(n, false);
            
            if (adj.find(u) != adj.end() && adj.find(v) != adj.end() &&
                dfs(u, v, adj, visited)) {
                return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};