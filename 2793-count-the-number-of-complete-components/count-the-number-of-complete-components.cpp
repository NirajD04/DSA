class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
 
        if(x_parent == y_parent) return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> edgeCount;  // root -> edge count
        unordered_map<int, int> vertexCount; // root -> vertex count

        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(auto &edge : edges) {
            Union(edge[0], edge[1]);
        }

        // Count vertices in each component
        for(int i = 0; i < n; i++) {
            int root = find(i);
            vertexCount[root]++;
        }

        // Count edges in each component
        for(auto &edge : edges) {
            int root = find(edge[0]); // same as find(edge[1])
            edgeCount[root]++;
        }

        int result = 0;
        for(auto &entry : vertexCount) {
            int root = entry.first;
            int v = entry.second;
            int e = edgeCount[root];

            // Check if the component is a complete graph
            if((v * (v - 1)) / 2 == e) {
                result++;
            }
        }

        return result;
    }
};
