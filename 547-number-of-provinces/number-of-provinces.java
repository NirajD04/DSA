class Solution {

    public void dfs(Map<Integer, List<Integer>> adj, int u, boolean[] visited) {
        visited[u] = true;

        for (int v : adj.get(u)) {
            if (!visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        HashMap<Integer, List<Integer>> mp= new HashMap();

        int n= isConnected.length;
        int m= isConnected[0].length;

      for (int i = 0; i < n; i++) {
            mp.put(i, new ArrayList<>());
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    mp.get(i).add(j);
                }
            }
        }

        boolean[] visited = new boolean[n];
        int count = 0;

        // DFS on all components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(mp, i, visited);
            }
        }

        return count;
    }
}