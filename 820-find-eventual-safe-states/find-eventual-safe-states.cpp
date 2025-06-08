class Solution {
public:
    vector<int> topologicalSortCheck(unordered_map<int, vector<int>>& adj,
                                     int n, vector<int>& indegree) {
        queue<int> que;
        int count = 0;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                result.push_back(i);
                que.push(i);
            }
        }

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (int& v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    result.push_back(v);
                    que.push(v);
                }
            }
        }

        sort(result.begin(), result.end());  // Optional: to return in sorted order
        return result;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        // Reverse the graph
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                adj[v].push_back(u);
                indegree[u]++;
            }
        }

        return topologicalSortCheck(adj, n, indegree);
    }
};
