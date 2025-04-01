class Solution {
public:
    bool DFS(vector<vector<int>>& graph, int& curr, vector<int>& color,
             int curentcolor) {
        color[curr] = curentcolor;

        for (int& neighbour : graph[curr]) {
            if (color[neighbour] == -1) {
                if (!DFS(graph, neighbour, color, 1 - curentcolor)) {
                    return false;
                } 
            }
            else if (color[neighbour] ==
                           color[curr]) { // Conflict detected
                    return false;
            }

        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1); // similar as visited

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {

                if (DFS(graph, i, color, 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};