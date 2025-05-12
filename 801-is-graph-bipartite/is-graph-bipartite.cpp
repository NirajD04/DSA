class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int node, vector<int>& color,
             int currentcolor) {
        color[node] = currentcolor;
        queue<int> q;

        q.push(node);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int& v : graph[u]) {
                if (color[u] == color[v]) {
                    return false;
                } else if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
            
        }
        return true;
    }
    // bool dfs(vector<vector<int>>& graph, int node, vector<int>& color,
    //          int currentcolor) {

    //     color[node] = currentcolor;

    //     for (int& v : graph[node]) {

    //         if (color[v] == color[node]) {
    //             return false;
    //         }
    //         if (color[v] == -1) {
    //             if (dfs(graph, v, color, 1 - currentcolor) == false) {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {

            if (color[i] == -1) {

                if (bfs(graph, i, color, 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};