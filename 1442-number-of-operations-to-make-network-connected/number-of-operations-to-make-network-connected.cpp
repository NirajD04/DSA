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
 
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        parent.resize(n);
        rank.resize(n,0);

        int m=connections.size();
        
        if(m<n-1){

            return -1;
        }


        
        for(int i=0; i<n; i++){
            parent[i]=i;
        }


        int component=n;

        for(auto &v: connections){

            
            if(find(v[0])!=find(v[1])){

                Union(v[0],v[1]);
                
                component--;
            }
        }
        return component-1;
    }
};


// class Solution {
// public:
//     void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
//         visited[node] = 1;
//         for(int ng : adj[node]) {
//             if(!visited[ng]) {
//                 dfs(ng, adj, visited);
//             }
//         }
//     }

//     int makeConnected(int n, vector<vector<int>>& connections) {
//         int m = connections.size();
        
//         // Not enough cables to connect all nodes
//         if(m < n-1) return -1;

//         // Build adjacency list
//         vector<vector<int>> adj(n);
//         for(auto &edge : connections) {
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }

//         // Count components using DFS
//         vector<int> visited(n, 0);
//         int components = 0;

//         for(int i = 0; i < n; i++) {
//             if(!visited[i]) {
//                 components++;
//                 dfs(i, adj, visited);
//             }
//         }

//         // We need (components - 1) extra cables
//         return components - 1;
//     }
// };
