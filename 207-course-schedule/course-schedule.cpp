class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);


        vector<int> indegree(numCourses, 0);
        queue<int> q;

        // Build adjacency list
        for (auto& pre : prerequisites) {
            int course = pre[0];    //preq--->course
            int prereq = pre[1];

            adj[prereq].push_back(course);

            indegree[course]++;
        }


        // Push nodes with zero indegree
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }



        int count = 0; // Track number of processed nodes
        while (!q.empty()) {

            int u = q.front();
            q.pop();
            count++;

            for (int& v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // If all courses are processed, return true
        return count == numCourses;
    }
};