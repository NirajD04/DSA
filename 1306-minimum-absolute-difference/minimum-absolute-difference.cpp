class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n=nums.size();

        int a=INT_MAX;
        int diff=0;

        for(int i=1; i<n; i++){
           diff=nums[i]-nums[i-1];
           a=min(a,diff);
        }

        vector<vector<int>> result;

        for(int i=1; i<n; i++){
            if(nums[i]-nums[i-1]==a){
                result.push_back({nums[i-1], nums[i]});
            }
        }
        return  result;
    }
};