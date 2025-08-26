class Solution {
public:
    void dfs(int node, vector<bool> &visited, unordered_map<int, vector<int>> &adj){
        if(visited[node]){
            return ;
        }

        visited[node]=true;
        
        for(int &ng: adj[node]){
            if(!visited[ng]){
                dfs(ng, visited, adj);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();

        unordered_map<int, vector<int>> adj;

        for(int i=0; i<n; i++){
            for(int j=0; j< n; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int count=0;

        for(int i=0;i< n; i++){
            if(!visited[i]){
                count++;
                dfs(i, visited, adj);
            }
        }

        return count;
    }
};