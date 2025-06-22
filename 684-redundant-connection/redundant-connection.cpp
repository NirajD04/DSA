class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]); // Path compression
    }
    
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
 
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1);

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if(find(u) == find(v)) {
                return edge;
            }

            Union(u, v);
        }
        return {};
    }
};
