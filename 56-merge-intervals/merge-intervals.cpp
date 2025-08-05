class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();

        sort(intervals.begin(), intervals.end());

        int i=0;
        while(i<n){
            int start= intervals[i][0];
            int  end= intervals[i][1];

            if(!ans.empty() && end <= ans.back()[1]){
                continue;
            }

            int j=0;
            for(j=i+1; j< n; j++){
                if(end >= intervals[j][0]){
                    end= max(intervals[j][1], end);
                }else{
                    break;
                }
                
            }
            
            ans.push_back({start, end});

            i=j;
        }

        return ans;
    }
};