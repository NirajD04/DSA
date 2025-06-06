class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();

        for(auto x:nums){
            mp[x]++;
        }

        set<int> ans;
        for(auto[key,value] : mp){
            if(value>n/3){
                ans.insert(key);
            }
        }

        vector<int> result(ans.begin(), ans.end());
        return result;
    }
};