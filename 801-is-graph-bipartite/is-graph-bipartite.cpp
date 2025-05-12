class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& color,
             int currentcolor) {

        color[node] = currentcolor;

        for (int& v : graph[node]) {

            if (color[v] == color[node]) {
                return false;
            }
            if (color[v] == -1) {
                if (dfs(graph, v, color, 1 - currentcolor) == false) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            
            if (color[i] == -1) {
                
                if (dfs(graph, i, color, 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};