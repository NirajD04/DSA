class Solution {
public: 

    vector<vector<int>> direction{{1,0}, {0,1}, {-1,0},{0,-1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));

        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;

            q.pop();

            for(auto dir: direction){
                int ni=i+dir[0];
                int nj=j+dir[1];

                if(ni>=0 && ni<m && nj>=0 && nj<n && dist[ni][nj]>dist[i][j]+1){


                    dist[ni][nj]=dist[i][j]+1;
                    q.push({ni,nj});
                }
            }
        }

        return dist;

    }
};