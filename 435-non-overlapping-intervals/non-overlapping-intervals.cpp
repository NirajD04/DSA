class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; }); // end time pe sort kiya

        int end = intervals[0][1];

        int count = 1;

        for (int i = 1; i < n; i++) {

            if (intervals[i][0] >= end) {

                count++;           // non overlapping , wale count kiya, jo ache hai , 
                
                end = intervals[i][1];           
            }
        }

        return intervals.size() - count;    // jo bache hoge unko remove;
    }
};