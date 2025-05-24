class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<p> pq;  //closet bola max heap

        for (int i = 0; i < points.size(); i++) {

            pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1],

                     {points[i][0], points[i][1]}});   // distance ,, aur point in heap

            if (pq.size() > k) {  // k 
                pq.pop();
            }
        }
        vector<vector<int>> ans;

        while (pq.size() > 0) {
            auto p = pq.top().second;

            ans.push_back({p.first, p.second});
            pq.pop();
        }
        return ans;
    }
};